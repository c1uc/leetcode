/*
Sparse Table (ST) Usage Guide

This template provides a generic Sparse Table for idempotent range queries (e.g., min, max, gcd) in O(1) time after O(N log N) preprocessing.

Example Usage:

#include <bits/stdc++.h>
using namespace std;

// Suppose you want to answer range maximum queries:
vector<int> a = {1, 5, 2, 4, 3};
ST<int> st(a); // By default, uses max

// Query maximum in [l, r):
int l = 1, r = 4;
int maximum = st.query(l, r); // returns max(a[1], a[2], a[3])

// For range minimum queries:
auto mn = [](int a, int b) { return min(a, b); };
ST<int> st_min(a, mn);
int minimum = st_min.query(l, r);

// For other types (e.g., long long, custom structs), specify the type and operation accordingly.

Template Parameters:
- T: The type of the elements (e.g., int, long long)
- op: The associative, idempotent operation (e.g., min, max, gcd)

Constructor:
ST(const vector<T>& a, function<T(T, T)> op = [](T a, T b) { return max(a, b); })

Query:
T query(int l, int r) const; // Returns op(a[l], ..., a[r-1])

Note:
- The range is [l, r), i.e., inclusive of l, exclusive of r.
- The operation must be idempotent (op(x, x) = x) for correctness.
*/
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class ST {
    vector<vector<T>> st;
    function<T(T, T)> op;

public:
    ST(const vector<T>& a, function<T(T, T)> op = [](T a, T b) { return max(a, b); }) : op(op) {
        size_t n = a.size();
        int w = bit_width(n);
        st.resize(w, vector<T>(n));
        for (int j = 0; j < n; j++) {
            st[0][j] = a[j];
        }
        for (int i = 1; i < w; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    // [l, r)
    T query(int l, int r) const {
        int k = bit_width((uint32_t) r - l) - 1;
        return op(st[k][l], st[k][r - (1 << k)]);
    }
};