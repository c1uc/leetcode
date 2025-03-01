/*
 * @lc app=leetcode id=2460 lang=cpp
 *
 * [2460] Apply Operations to an Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < nums.size() - 1;i++) {
            if(nums[i] == 0) {
                nums.erase(nums.begin() + i);
                i--;
            } else if(nums[i] == nums[i + 1]) {
                nums[i] = 2 * nums[i];
                nums.erase(nums.begin() + i + 1);
            }
        }

        while(nums.size() < n) {
            nums.emplace_back(0);
        }
        return nums;
    }
};
// @lc code=end

