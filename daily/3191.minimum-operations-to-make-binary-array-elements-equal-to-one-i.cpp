/*
 * @lc app=leetcode id=3191 lang=cpp
 *
 * [3191] Minimum Operations to Make Binary Array Elements Equal to One I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c = 0;
        for(int i = 0;i < nums.size() - 2;i++) {
            if(nums[i] == 0) {
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
                ++c;
            }
        }
        return nums[nums.size() - 2] == 1 && nums[nums.size() - 1] == 1 ? c : -1;
    }
};
// @lc code=end

