const int MAXN = 501;
// static int dp[MAXN][3];

class Solution {
public:
    int maximumAmount(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        auto dp = vector(m, vector(3, -INT_MAX / 2ll));
        dp[0][0] = 0;
        for(int i = 0;i < n;i++) {
            if(g[i][0] < 0) {
                dp[0][2] = max({dp[0][2] + g[i][0], dp[0][1]});
                dp[0][1] = max({dp[0][1] + g[i][0], dp[0][0]});
            } else {
                dp[0][2] += g[i][0];
                dp[0][1] += g[i][0];
            }
            dp[0][0] += g[i][0];
            for(int j = 1;j < m;j++) {
                if(g[i][j] < 0) {
                    dp[j][2] = max({dp[j][2] + g[i][j], dp[j - 1][2] + g[i][j], dp[j][1], dp[j - 1][1]});
                    dp[j][1] = max({dp[j][1] + g[i][j], dp[j - 1][1] + g[i][j], dp[j][0], dp[j - 1][0]});
                } else {
                    dp[j][2] = max(dp[j - 1][2], dp[j][2]) + g[i][j];
                    dp[j][1] = max(dp[j - 1][1], dp[j][1]) + g[i][j];
                }
                dp[j][0] = max(dp[j][0], dp[j - 1][0]) + g[i][j];
            }
        }
        return ranges::max(dp[m - 1]);
    }
};
