/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), farthest = 0, end = 0, ans = 0;
        for(int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if(i == end) {
                end = farthest;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

