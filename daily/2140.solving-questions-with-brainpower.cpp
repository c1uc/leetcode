/*
 * @lc app=leetcode id=2140 lang=cpp
 *
 * [2140] Solving Questions With Brainpower
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

long long dp[100001];

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        memset(dp, 0, sizeof(dp));
        
        for(int i = n - 1;i >= 0;i--) {
            if(i + questions[i][1] + 1 <= n) {
                dp[i] = max(dp[i + 1], questions[i][0] + dp[i + questions[i][1] + 1]);
            } else {
                dp[i] = max(dp[i + 1], (long long)questions[i][0]);
            }
        }
        return dp[0];
    }
};
// @lc code=end

