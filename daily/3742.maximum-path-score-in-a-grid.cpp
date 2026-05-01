class Solution {
public:
    int maxPathScore(vector<vector<int>>& g, int k) {
        int m = g.size(), n = g[0].size();
        auto dp = vector(n, vector(k + 1, -INT_MAX));
        dp[0][0] = 0;
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(g[i][j]) {
                    for(int t = k;t > 0;t--) {
                        dp[j][t] = max(dp[j][t - 1], j > 0 ? dp[j - 1][t - 1] : -INT_MAX) + g[i][j];
                    }
                    dp[j][0] = -INT_MAX;
                } else {
                    for(int t = 0;t <= k;t++) dp[j][t] = max(dp[j][t], j > 0 ? dp[j - 1][t] : -INT_MAX);
                }
            }
        }
        return [&]() { auto res = ranges::max(dp[n - 1]); return res < 0 ? -1 : res;}();
    }
};
