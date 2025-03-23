/*
 * @lc app=leetcode id=2206 lang=cpp
 *
 * [2206] Divide Array Into Equal Pairs
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        bool c[501] = {false};
        for(auto& x: nums) {
            c[x] ^= true;
        }
        for(auto& b: c) {
            if(b) return false;
        }
        return true;
    }
};
// @lc code=end

