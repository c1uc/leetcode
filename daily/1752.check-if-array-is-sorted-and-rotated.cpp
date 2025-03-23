/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size() == 1) return true;
        if(nums[0] < nums.back()) return is_sorted(nums.begin(), nums.end());
        int n = nums.size();
        bool flag = true;
        for(int i = 1;i < n;i++) {
            if(nums[i] < nums[i - 1]) {
                if (flag) {
                    flag = false;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

