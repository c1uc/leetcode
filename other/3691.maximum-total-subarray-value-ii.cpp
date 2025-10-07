#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

class Solution {
    using ti = tuple<int, int, int>;
    public:
        long long maxTotalValue(vector<int>& nums, int k) {
            int n = nums.size();
            auto mx = [](int a, int b) { return max(a, b); };
            auto mn = [](int a, int b) { return min(a, b); };
            ST<int> st_mx(nums, mx);
            ST<int> st_mn(nums, mn);

            long long ans = 0;
            priority_queue<ti, vector<ti>, greater<>> pq;
            for(int i = 0; i < n; i++) {
                pq.emplace(st_mx.query(i, n) - st_mn.query(i, n), i, n); // subarray value, left, right
            }
            while(k) {
                auto [val, l, r] = pq.top();
                pq.pop();
                ans += val;
                if(r > l + 1)
                    pq.emplace(st_mx.query(l, r - 1) - st_mn.query(l, r - 1), l, r - 1);
                --k;
            }
            return ans;
            
        }
    };
