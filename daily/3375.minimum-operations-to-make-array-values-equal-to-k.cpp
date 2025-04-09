/*
 * @lc app=leetcode id=3375 lang=cpp
 *
 * [3375] Minimum Operations to Make Array Values Equal to K
 */

// @lc code=start
#include <bits/stdc++.h>
#include <ranges>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return ranges::any_of(nums, [&](int x) { return x < k; }) ? -1 : unordered_set<int>(nums.begin(), nums.end()).size() - ranges::any_of(nums, [&](int x) { return x == k; });
    }
};
// @lc code=end

