const int MAXN = 1002;
const int MOD = 1e9 + 7;
int dp[MAXN][MAXN][2] = {0};

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, 0, sizeof(int) * MAXN * MAXN * 2);
        for(int i = 1;i <= min(limit, zero);i++) dp[i][0][0] = 1;
        for(int i = 1;i <= min(limit, one);i++) dp[0][i][1] = 1;
        for(int z = 1;z <= zero;z++) for(int o = 1;o <= one;o++) {
            dp[z][o][0] = (dp[z - 1][o][0] + dp[z - 1][o][1]) % MOD;
            dp[z][o][1] = (dp[z][o - 1][0] + dp[z][o - 1][1]) % MOD;

            if(z > limit) dp[z][o][0] -= dp[z - limit - 1][o][1];
            if(o > limit) dp[z][o][1] -= dp[z][o - limit - 1][0];

            dp[z][o][0] = (dp[z][o][0] + MOD) % MOD;
            dp[z][o][1] = (dp[z][o][1] + MOD) % MOD;
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
