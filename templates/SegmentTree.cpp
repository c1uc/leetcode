/*
Segment Tree (ST) Template

Features:
- Supports generic type T and any associative operation (e.g., sum, min, max, custom types).
- Supports point update and range query.
- Accepts the combining function as a constructor argument (default: sum).
- Array is zero-indexed.

Usage:
    vector<int> a = {1, 2, 3, 4, 5};
    SegmentTree<int> st(a); // Default: sum
    int s = st.query(1, 4); // sum of a[1..3]
    st.update(2, 10); // a[2] = 10
    int s2 = st.query(1, 4);

    // For custom type or function:
    auto mx = [](int a, int b) { return max(a, b); };
    SegmentTree<int> st_max(a, mx, INT_MIN);

Template Parameters:
- T: Value type (e.g. int, long long, custom struct)
- op: Associative binary function: T (T, T)
- e: Identity element for the operation

Implements:
- build
- point update
- range query [l, r) (inclusive l, exclusive r)
*/

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class SegmentTree {
    int n;
    vector<T> tree;
    function<T(const T&, const T&)> op;
    T e; // identity element

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

    void set(int u, int l, int r, int idx, const T& val) {
        if (l + 1 == r) {
            tree[u] = val;
            return;
        }
        int m = (l + r) / 2;
        if (idx < m)
            set(2*u+1, l, m, idx, val);
        else
            set(2*u+2, m, r, idx, val);
        tree[u] = op(tree[2*u+1], tree[2*u+2]);
    }

    T range(int u, int l, int r, int ql, int qr) const {
        if (qr <= l || r <= ql) return e;
        if (ql <= l && r <= qr) return tree[u];
        int m = (l + r) / 2;
        return op(range(2*u+1, l, m, ql, qr), range(2*u+2, m, r, ql, qr));
    }

public:
    SegmentTree(const vector<T> &a,
        function<T(const T&, const T&)> op = [](const T& a, const T& b){ return a + b; },
        T e = T{0}
    ) : n(a.size()), op(op), e(e) {
        tree.resize(4 * n, e);
        if(n > 0) build(a, 0, 0, n);
    }

    // Point update: set a[idx] = val
    void update(int idx, const T& val) {
        set(0, 0, n, idx, val);
    }

    // Range query: op(a[l], a[l+1], ..., a[r-1])
    T query(int l, int r) const {
        return range(0, 0, n, l, r);
    }

    // If needed: get original value a[idx]
    T at(int idx) const {
        return query(idx, idx+1);
    }
};
