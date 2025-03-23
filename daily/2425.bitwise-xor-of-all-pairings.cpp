/*
 * @lc app=leetcode id=2425 lang=cpp
 *
 * [2425] Bitwise XOR of All Pairings
 */

// @lc code=start
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        if(nums2.size() & 1) {
            for(auto& x: nums1) res ^= x;
        }
        if(nums1.size() & 1) {
            for(auto& x: nums2) res ^= x;
        }
        return res;
    }
};
// @lc code=end

