#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minimumDeleteSum(string s1, string s2) {
            int dp[1001][1001] = {0};
            int n = s1.size(), m = s2.size();
            for(int i = 1;i <= n;i++) {
                for(int j = 1;j <= m;j++) {
                    if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + (int)s1[i - 1];
                    else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            int ans = 0;
            for(auto c: s1) ans += c;
            for(auto c: s2) ans += c;
            return ans - 2 * dp[n][m];
        }
    };
