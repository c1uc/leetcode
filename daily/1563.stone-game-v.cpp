#include <cstring>

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int prefix[n + 1];
        memset(prefix, 0, sizeof(prefix));
        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        for(int i=1;i<=n;i++) prefix[i] = prefix[i-1] + stoneValue[i-1];

        for(int j=1;j<n;j++)
        {
            for(int i=j-1;i>=0;i--)
            {
                for(int k=i;k<j;k++)
                {
                    int l = prefix[k+1] - prefix[i];
                    int r = prefix[j+1] - prefix[k+1];
                    if (l < r)
                    {
                        dp[i][j] = max(dp[i][j], l + dp[i][k]);
                    }
                    else if (l > r)
                    {
                        dp[i][j] = max(dp[i][j], r + dp[k+1][j]);
                    }
                    else
                    {
                        int max_ = max(l + dp[i][k], r + dp[k+1][j]);
                        dp[i][j] = max(dp[i][j], max_);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
