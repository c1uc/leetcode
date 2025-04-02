/*
 * @lc app=leetcode id=3350 lang=cpp
 *
 * [3350] Adjacent Increasing Subarrays Detection II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int len = 1, prev_len = 0, ans = 0;
        for(int i = 1;i < n;++i) {
            if(nums[i] > nums[i - 1]) {
                len++;
            } else {
                prev_len = len;
                len = 1;
            }
            ans = max(ans, max(len >> 1, min(prev_len, len)));
        }
        return ans;
    }
};
// @lc code=end

