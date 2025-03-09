/*
 * @lc app=leetcode id=3208 lang=cpp
 *
 * [3208] Alternating Groups II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;
        int n = colors.size();
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n + k - 2 && colors[j % n] != colors[(j + 1) % n]) {
                j++;
            }
            int len = j - i + 1;
            ans += len >= k ? len - k + 1 : 0;
            i = j;
        }
        return ans;
    }
};
// @lc code=end

