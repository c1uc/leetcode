#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long maximumProfit(vector<int>& prices, int k) {
            vector<vector<array<long long, 3>>> dp(prices.size() + 1, vector<array<long long, 3>>(k + 2, {INT_MIN / 2, INT_MIN / 2, INT_MIN / 2}));
            for(int i = 1;i <= k + 1;i++) {
                dp[0][i][0] = 0;
            }
            for(int i = 0;i < prices.size();i++) {
                int p = prices[i];
                for(int j = 1;j <= k + 1;j++) {
                    dp[i + 1][j][0] = max({dp[i][j][0], dp[i][j][1] + p, dp[i][j][2] - p});
                    dp[i + 1][j][1] = max(dp[i][j][1], dp[i][j - 1][0] - p);
                    dp[i + 1][j][2] = max(dp[i][j][2], dp[i][j - 1][0] + p);
                }
            }
            return dp[prices.size()][k + 1][0];
        }
    };
