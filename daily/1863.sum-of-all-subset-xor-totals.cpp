/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, [](int a, int b) {
            return a | b;
        }) * (1 << (nums.size() - 1));
    }
};
// @lc code=end

