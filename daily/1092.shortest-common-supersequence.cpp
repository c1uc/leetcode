/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= str1.size(); i++) {
            for (int j = 1; j <= str2.size(); j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string res = "";
        int i = str1.size(), j = str2.size();
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                res = str1[i - 1] + res;
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                res = str1[i - 1] + res;
                i--;
            } else {
                res = str2[j - 1] + res;
                j--;
            }
        }
        while (i > 0) {
            res = str1[i - 1] + res;
            i--;
        }
        while (j > 0) {
            res = str2[j - 1] + res;
            j--;
        }
        return res;
    }
};
// @lc code=end

