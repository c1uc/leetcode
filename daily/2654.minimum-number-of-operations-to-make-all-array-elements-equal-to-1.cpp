#include <bits/stdc++.h>
#include <ranges>
using namespace std;

auto gcd_ = [](this auto&& gcd_, int a, int b) -> int {
    return b == 0 ? a : gcd_(b, a % b);
};

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
    public:
        int minOperations(vector<int>& nums) {
            if(ranges::any_of(nums, [&](int x) { return x == 1; })) {
                return nums.size() - ranges::count(nums, 1);
            }
            int n = nums.size();
            for(int i = 1, cur = nums[0];i < n;i++) {
                cur = gcd_(cur, nums[i]);
                if(i == n - 1 && cur != 1) return -1;
            }
            ST<int> st(nums, gcd_);
            int l = 0, ans = 2 * n;
            for(int r = 1;r <= n;r++) {
                while(l + 1 < r && st.query(l + 1, r) == 1) l++;
                if(st.query(l, r) == 1) ans = min(ans, r - l + n - 2);
            }
            return ans;
        }
    };
