/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), furtherest = 0;
        for(int i = 0;i < n - 1;i++) {
            if(i > furtherest) return false;
            furtherest = max(furtherest, i + nums[i]);
        }
        return furtherest >= n - 1;
    }
};
// @lc code=end

