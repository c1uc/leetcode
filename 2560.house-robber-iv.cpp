/*
 * @lc app=leetcode id=2560 lang=cpp
 *
 * [2560] House Robber IV
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        
        auto valid = [&](int x) {
            int c = 0, i = 0;
            for(;i < nums.size();i++) {
                if(nums[i] <= x) {
                    ++c;
                    ++i;
                }
            }
            return c >= k;
        };

        int l = 0, r = *max_element(nums.begin(), nums.end()), mid;
        while(l + 1 < r) {
            mid = (l + r) >> 1;
            if(valid(mid)) r = mid;
            else l = mid;
        }
        return r;
    }
};
// @lc code=end

