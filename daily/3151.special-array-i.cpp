/*
 * @lc app=leetcode id=3151 lang=cpp
 *
 * [3151] Special Array I
 */

// @lc code=start
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 1) return true;
        for(int i = 1;i < nums.size();i++) {
            if((nums[i - 1] & 1) ^ (nums[i] & 1)) continue;
            return false;
        }
        return true;
    }
};
// @lc code=end

