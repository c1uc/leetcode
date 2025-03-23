/*
 * @lc app=leetcode id=2529 lang=cpp
 *
 * [2529] Maximum Count of Positive Integer and Negative Integer
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int p = 0, n = 0;
        for(auto x: nums) {
            if(x > 0) p++;
            if(x < 0) n++;
        }
        return max(p, n);
    }
};
// @lc code=end

