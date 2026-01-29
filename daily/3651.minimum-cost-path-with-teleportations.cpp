#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minCost(vector<vector<int>>& g, int k) {
            int n = g.size(), m = g[0].size();
            if(k > 0 && g[0][0] > g[n - 1][m - 1]) return 0;

            int mx = 0;
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < m;j++) {
                    mx = max(mx, g[i][j]);
                }
            }

            vector<int> dp(m + 1, INT_MAX);
            vector<int> suf_min(mx + 2, INT_MAX);
            for(int t = 0;t <= k;t++) {
                fill(dp.begin(), dp.end(), INT_MAX / 2);
                dp[1] = 0;
                vector<int> n_min(mx + 1, INT_MAX);
                for(int i = 0;i < n;i++) {
                    for(int j = 0;j < m;j++) {
                        int x = g[i][j];
                        if(i != 0 || j != 0)
                            dp[j + 1] = min({dp[j + 1] + x, dp[j] + x, suf_min[x]});
                        n_min[x] = min(n_min[x], dp[j + 1]);
                    }
                }
                auto tmp = suf_min;
                for(int x = mx;x >= 0;x--) {
                    suf_min[x] = min(suf_min[x + 1], n_min[x]);
                }
                if(suf_min == tmp) break;
            }
            return dp[m];
        }
    };
