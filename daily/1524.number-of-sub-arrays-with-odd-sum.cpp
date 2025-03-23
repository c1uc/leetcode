/*
 * @lc app=leetcode id=1524 lang=cpp
 *
 * [1524] Number of Sub-arrays With Odd Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;
        int dp[2] = {1, 0};
        bool sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum ^= arr[i] & 1;
            ans += dp[!sum];
            ans %= 1000000007;
            dp[sum]++;
        }

        return ans;
    }
};
// @lc code=end

