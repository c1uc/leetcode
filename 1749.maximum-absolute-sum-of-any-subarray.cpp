/*
 * @lc app=leetcode id=1749 lang=cpp
 *
 * [1749] Maximum Absolute Sum of Any Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0, pos = 0, neg = 0;
        for(auto& x: nums) {
            pos += x;
            neg += x;
            if(pos < 0) pos = 0;
            if(neg > 0) neg = 0;
            ans = max(max(pos, ans), abs(neg));
        }

        return ans;
    }
};
// @lc code=end

