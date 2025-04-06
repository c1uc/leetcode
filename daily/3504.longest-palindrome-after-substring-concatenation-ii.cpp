/*
 * @lc app=leetcode id=3504 lang=cpp
 *
 * [3504] Longest Palindrome After Substring Concatenation II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> ss(n, 0), tt(m, 0);
        for(int i = 0;i < n;++i) {
            int l = 0;
            while(i - l >= 0 && i + l < n && s[i - l] == s[i + l]) {
                ss[i - l] = max(ss[i - l], 2 * l + 1);
                l++;
            }
            l = 0;
            while(i - l >= 0 && i + l + 1 < n && s[i - l] == s[i + l + 1]) {
                ss[i - l] = max(ss[i - l], 2 * l + 2);
                l++;
            }
        }
        for(int i = 0;i < m;++i) {
            int l = 0;
            while(i - l >= 0 && i + l < m && t[i - l] == t[i + l]) {
                tt[i + l] = max(tt[i + l], 2 * l + 1);
                l++;
            }
            l = 0;
            while(i - l >= 0 && i + l + 1 < m && t[i - l] == t[i + l + 1]) {
                tt[i + l + 1] = max(tt[i + l + 1], 2 * l + 2);
                l++;
            }
        }
        for(int i = 0;i < n;++i) {
            dp[i][0] = ss[i];
        }
        for(int i = 1;i <= m;++i) {
            dp[n][i] = tt[i - 1];
        }
        int ans = 0;
        for(int i = n - 1;i >= 0;--i) {
            for(int j = 1;j <= m;++j) {
                dp[i][j] = max(ss[i], tt[j - 1]);
                if(s[i] == t[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
                }
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};
// @lc code=end

