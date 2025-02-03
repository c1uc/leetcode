/*
 * @lc app=leetcode id=3105 lang=cpp
 *
 * [3105] Longest Strictly Increasing or Strictly Decreasing Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, l = 1, inc = 0;
        for(int i = 1;i < nums.size();i++) {
            if(inc == 0) {
                if(nums[i] > nums[i - 1]) {
                    inc = 1;
                    l = 2;
                } else if(nums[i] < nums[i - 1]) {
                    inc = -1;
                    l = 2;
                } else {
                    l = 1;
                }
            } else if(inc == 1) {
                if(nums[i] > nums[i - 1]) {
                    l++;
                } else if(nums[i] < nums[i - 1]) {
                    inc = -1;
                    l = 2;
                } else {
                    inc = 0;
                    l = 1;
                }
            } else {
                if(nums[i] > nums[i - 1]) {
                    inc = 1;
                    l = 2;
                } else if(nums[i] < nums[i - 1]) {
                    l++;
                } else {
                    inc = 0;
                    l = 1;
                }
            }
            ans = max(ans, l);
        }
        return ans;
    }
};
// @lc code=end

