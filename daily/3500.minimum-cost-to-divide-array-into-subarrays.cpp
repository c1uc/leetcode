/*
 * @lc app=leetcode id=3500 lang=cpp
 *
 * [3500] Minimum Cost to Divide Array Into Subarrays
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n = nums.size();
        vector<long long> dp(n + 1, 0);
        for(int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
            cost[i] += cost[i - 1];
        }
        for(int i = n - 1; i >= 0; i--) {
            dp[i] = (long long)(nums[i] + k) * (cost[i] - (i > 0 ? cost[i - 1] : 0)) + dp[i + 1] + k * (cost[n - 1] - cost[i]);
            for(int j = i + 1; j < n; j++) {
                dp[i] = min(dp[i], (long long)(nums[j] + k) * (cost[j] - (i > 0 ? cost[i - 1] : 0)) + dp[j + 1] + k * (cost[n - 1] - cost[j]));
            }
        }
        return dp[0];
    }
};
// @lc code=end

