/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> pre(n, -1);

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < i;j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }
        }

        int mx = 0, idx = 0;
        for(int i = 0;i < n;i++) {
            if(dp[i] > mx) {
                mx = dp[i];
                idx = i;
            }
        }

        vector<int> ans;
        while(idx != -1) {
            ans.push_back(nums[idx]);
            idx = pre[idx];
        }

        return ans;
    }
};
// @lc code=end

