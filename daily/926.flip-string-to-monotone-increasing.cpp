/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + (s[i - 1] == '1' ? 1 : 0);
        }
        int ans = INT_MAX;
        for(int i = 0; i <= n; i++) {
            ans = min(ans, dp[i] + n - i - (dp[n] - dp[i]));
        }
        return ans;
    }
};
// @lc code=end

