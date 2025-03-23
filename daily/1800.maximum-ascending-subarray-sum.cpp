/*
 * @lc app=leetcode id=1800 lang=cpp
 *
 * [1800] Maximum Ascending Subarray Sum
 */

// @lc code=start
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int s = nums[0], ans = nums[0];
        for(int i = 1;i < nums.size();i++) {
            if(nums[i] > nums[i - 1]) s += nums[i];
            else s = nums[i];
            ans = max(ans, s);
        }
        return ans;
    }
};
// @lc code=end

