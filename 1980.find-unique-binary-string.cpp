/*
 * @lc app=leetcode id=1980 lang=cpp
 *
 * [1980] Find Unique Binary String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string s(nums.size(), '0');

        auto f = [&](auto&& self, int i) -> bool {
            if (i == s.size()) {
                return find(nums.begin(), nums.end(), s) == nums.end();
            }
            s[i] = '0';
            if (self(self, i + 1)) return true;
            s[i] = '1';
            return self(self, i + 1);
        };

        f(f, 0);
        return s;
    }
};
// @lc code=end