/*
 * @lc app=leetcode id=2818 lang=cpp
 *
 * [2818] Apply Operations to Maximize Score
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
constexpr ll MOD = 1e9 + 7;
constexpr ll MAX_N = 1e5 + 5;

vector<int> prime_score(MAX_N, 0);
auto init_prime_score = []() {
    for (int i = 2; i <= MAX_N; i++) {
        if(prime_score[i] == 0) {
            for(int j = i; j <= MAX_N; j += i) ++prime_score[j];
        }
    }
    return 0;
}();

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        st.push(0);
        for (int i = 1; i < n; i++) {
            while (!st.empty() && prime_score[nums[st.top()]] < prime_score[nums[i]]) {
                right[st.top()] = i;
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) {
            right[st.top()] = n;
            st.pop();
        }
        priority_queue<pii, vector<pii>, less<pii>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], (ll)(right[i] - i) * (i - left[i])});
        }

        auto pow = [](ll a, ll b) {
            ll res = 1;
            while (b) {
                if (b & 1) res = res * a % MOD;
                a = a * a % MOD;
                b >>= 1;
            }
            return res;
        };

        ll ans = 1;
        while(k) {
            auto [val, len] = pq.top();
            pq.pop();
            ans = (ans * pow(val, min(len, (ll)k))) % MOD;
            k -= min(len, (ll)k);
        }
        return ans;
    }
};
// @lc code=end

