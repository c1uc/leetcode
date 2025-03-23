/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0, 0, 0};
        int n = s.size();
        int l = 0, r = 0, extra = 0;
        int ans = 0;

        auto is_valid = [&]() {
            return count[0] > 0 && count[1] > 0 && count[2] > 0;
        };

        auto is_redundant = [&](char c) {
            return count[c - 'a'] > 1 && count[0] > 0 && count[1] > 0 && count[2] > 0;
        };

        for(; r < n; r++) {
            count[s[r] - 'a']++;

            while (l <= r && is_redundant(s[l])) {
                extra++;
                count[s[l] - 'a']--;
                l++;
            }

            if (is_valid()) {
                ans += extra + 1;
            }
        }

        return ans;
    }
};
// @lc code=end

