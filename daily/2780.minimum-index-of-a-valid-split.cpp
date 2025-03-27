/*
 * @lc app=leetcode id=2780 lang=cpp
 *
 * [2780] Minimum Index of a Valid Split
 */

// @lc code=start
#include <bits/stdc++.h>
#include <ranges>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        vector<int> nums_copy = nums;
        ranges::nth_element(nums_copy, nums_copy.begin() + nums_copy.size() / 2);
        int target = nums_copy[nums_copy.size() / 2];
        int cnt = 0;
        for(auto x : nums_copy) {
            if(x == target) cnt++;
        }
        if(cnt * 2 <= nums_copy.size()) return -1;
        int left_cnt = 0;
        for(int i = 0; i < nums_copy.size(); i++) {
            if(nums[i] == target) left_cnt++;
            if(left_cnt * 2 > i + 1 && (cnt - left_cnt) * 2 > nums_copy.size() - i - 1) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

