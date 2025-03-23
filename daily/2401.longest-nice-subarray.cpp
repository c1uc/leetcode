/*
 * @lc app=leetcode id=2401 lang=cpp
 *
 * [2401] Longest Nice Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;

        for(int i = 0, idx = 0, mask = 0;i < nums.size();i++) {
            while((mask & nums[i]) && idx < i) {
                mask ^= nums[idx];
                ++idx;
            }
            mask |= nums[i];
            ans = max(ans, i - idx + 1);
        }

        return ans;
    }
};
// @lc code=end

