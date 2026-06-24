const int MAXN = 2001, MOD = 1e9 + 7;
vector<vector<int>> dp(2, vector(MAXN, 0));

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        ranges::fill(dp[0], 1);
        ranges::fill(dp[1], 1);
        // for(int i = l;i <= r;i++) {
        //     dp0[i] = 1;
        //     dp1[i] = 1;
        // }
        int s0, s1;
        for(int _ = 1;_ < n;_++) {
            s0 = 0;
            s1 = 0;
            for(int i = l;i <= r;i++) {
                int t = dp[1][i];
                dp[1][i] = s0;
                s0 += t;
                s0 %= MOD;
            }

            for(int i = r;i >= l;i--) {
                int t = dp[0][i];
                dp[0][i] = s1;
                s1 += t;
                s1 %= MOD;
            }
            swap(dp[0], dp[1]);
        }
        long long res = 0;
        for(int i = l;i <= r;i++) res = (res + dp[0][i] + dp[1][i]) % MOD;
        return res % MOD;
    }
};
