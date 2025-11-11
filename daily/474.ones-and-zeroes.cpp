#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int findMaxForm(vector<string>& strs, int m, int n) {
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
            for(auto &s: strs) {
                int cnt0 = count(s.begin(), s.end(), '0');
                int cnt1 = count(s.begin(), s.end(), '1');
                for(int i = m;i >= cnt0;i--) {
                    for(int j = n;j >= cnt1;j--) {
                        dp[i][j] = max(dp[i][j], dp[i - cnt0][j - cnt1] + 1);
                    }
                }
            }
            return dp[m][n];
        }
    };