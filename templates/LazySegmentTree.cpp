/*
Lazy Segment Tree (LST) Template

Features:
- Generic lazy segment tree with range updates (delta or assign) and range queries.
- Customizable combine (op), apply (apply), and lazy composition (compose) functions.
- Defaults implement range add (delta) + range sum for arithmetic types.
- Array is zero-indexed.

Usage (range add + range sum, delta style):
    vector<long long> a = {1, 2, 3, 4, 5};
    LazySegmentTree<long long, long long> st(a); // tag is delta
    st.update(1, 4, 2); // add +2 to a[1..3]
    long long s = st.query(0, 5); // sum of a[0..4]

Custom behavior example (range assign + range min):
    using T = long long;
    using L = optional<long long>; // lazy tag: value to assign or nullopt
    auto op = [](T a, T b){ return min(a, b); };
    auto apply = [](const T& cur, const L& tag, int len){
        return tag ? *tag : cur;
    };
    auto compose = [](const L& a, const L& b){ return b ? b : a; }; // newer overrides
    LazySegmentTree<T, L> st(a, op, (long long)4e18, apply, compose, nullopt);

Template Parameters:
- T: Node value type.
- L: Lazy tag type (delta, assign value, etc.).
- op: Associative binary function: T (T, T).
- apply: Function to apply lazy tag to a node value over segment length.
- compose: Function to combine two lazy tags (existing, incoming) => merged tag.
- e: Identity element for op.
- id: Identity element for lazy tags (means "no pending update").
*/

#include <bits/stdc++.h>
using namespace std;

template<typename T, typename L>
class LazySegmentTree {
    int n;
    vector<T> tree;
    vector<L> lazy;
    function<T(const T&, const T&)> op;
    function<T(const T&, const L&, int)> apply; // apply lazy delta/tag to node value
    function<L(const L&, const L&)> compose;   // merge existing (first) and new (second) tag
    T e;   // identity for op
    L id;  // identity for lazy (no-op)

    void build(const vector<T> &a, int u, int l, int r) {
        if (l + 1 == r) {
            tree[u] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(a, 2*u+1, l, m);
        build(a, 2*u+2, m, r);
        tree[u] = op(tree[2*u+1], tree[2*u+2]);
    }

    void apply_to_node(int u, int l, int r, const L& tag) {
        if (tag == id) return;
        tree[u] = apply(tree[u], tag, r - l);
        lazy[u] = compose(lazy[u], tag);
    }

    void push(int u, int l, int r) {
        if (lazy[u] == id || l + 1 == r) return;
        int m = (l + r) / 2;
        apply_to_node(2*u+1, l, m, lazy[u]);
        apply_to_node(2*u+2, m, r, lazy[u]);
        lazy[u] = id;
    }

    void range_update(int u, int l, int r, int ql, int qr, const L& tag) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            apply_to_node(u, l, r, tag);
            return;
        }
        push(u, l, r);
        int m = (l + r) / 2;
        range_update(2*u+1, l, m, ql, qr, tag);
        range_update(2*u+2, m, r, ql, qr, tag);
        tree[u] = op(tree[2*u+1], tree[2*u+2]);
    }

    T range_query(int u, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) return e;
        if (ql <= l && r <= qr) return tree[u];
        push(u, l, r);
        int m = (l + r) / 2;
        return op(range_query(2*u+1, l, m, ql, qr), range_query(2*u+2, m, r, ql, qr));
    }

public:
    LazySegmentTree(
        const vector<T> &a,
        function<T(const T&, const T&)> op = [](const T& a, const T& b){ return a + b; },
        T e = T{0},
        function<T(const T&, const L&, int)> apply = [](const T& cur, const L& tag, int len){
            // delta update: add tag * length to the segment aggregate
            return cur + static_cast<T>(tag) * len;
        },
        function<L(const L&, const L&)> compose = [](const L& a, const L& b){
            // existing then incoming for delta accumulation
            return a + b;
        },
        L id = L{0}
    ) : n(a.size()), op(op), apply(apply), compose(compose), e(e), id(id) {
        tree.assign(4 * max(1, n), e);
        lazy.assign(4 * max(1, n), id);
        if (n > 0) build(a, 0, 0, n);
    }

    // Range update: apply tag (delta by default) to [l, r)
    void update(int l, int r, const L& tag) {
        range_update(0, 0, n, l, r, tag);
    }

    // Convenience alias for delta-style updates
    void add(int l, int r, const L& delta) {
        update(l, r, delta);
    }

    // Range query: op(a[l], a[l+1], ..., a[r-1])
    T query(int l, int r) {
        return range_query(0, 0, n, l, r);
    }

    // If needed: point value after lazy propagation
    T at(int idx) {
        return query(idx, idx + 1);
    }
};
