const int MAXN = 201;
const int MOD = 1e9 + 7;
static int GCD[MAXN][MAXN];

auto init = []() {
    for(int i = 0;i < MAXN;i++) GCD[0][i] = GCD[i][0] = i;
    for(int i = 1;i < MAXN;i++) for(int j = 1;j < MAXN;j++) GCD[i][j] = gcd(i, j);
    return 'c';
}();

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        auto dp = vector(MAXN, vector(MAXN, 0));
        dp[0][0] = 1;
        for(auto x: nums) {
            auto new_dp = vector(MAXN, vector(MAXN, 0));
            for(int i = 0;i < MAXN;i++) {
                for(int j = 0;j < MAXN;j++) {
                    new_dp[i][j] = (new_dp[i][j] + dp[i][j]) % MOD;
                    new_dp[GCD[x][i]][j] = (new_dp[GCD[x][i]][j] + dp[i][j]) % MOD;
                    new_dp[i][GCD[x][j]] = (new_dp[i][GCD[x][j]] + dp[i][j]) % MOD;
                }
            }
            dp = move(new_dp);
        }
        int ans = 0;
        for(int i = 1;i < MAXN;i++) ans = (ans + dp[i][i]) % MOD;
        return ans;
    }
};
