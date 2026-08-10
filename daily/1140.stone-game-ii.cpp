class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector dp(n + 1, vector(n + 1, 0));
        int suf = 0;
        for(int i = n - 1;i >= 0;i--) {
            suf += piles[i];
            for(int m = 1;m <= (i / 2) + 1;m++) {
                if(i + 2 * m >= n) {
                    dp[i][m] = suf;
                    continue;
                }
                int mn = INT_MAX;
                for(int k = 1;k <= 2 * m;k++) {
                    mn = min(mn, dp[i + k][max(k, m)]);
                }
                dp[i][m] = suf - mn;
            }
        }
        return dp[0][1];
    }
};
