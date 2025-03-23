/*
 * @lc app=leetcode id=2364 lang=cpp
 *
 * [2364] Count Number of Bad Pairs
 */

// @lc code=start
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        ll ans = 0;
        for(int i = 0;i < nums.size();i++) {
            ans += i - m[i - nums[i]]++;
        }
        return ans;
    }
};
// @lc code=end

