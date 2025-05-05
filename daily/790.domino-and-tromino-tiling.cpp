#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;

class Solution {
public:
    int numTilings(int n) {
        vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + (i > 1 ? dp[i - 2][0] : 0)) % MOD;
            dp[i][1] = (dp[i - 1][1] + (i > 1 ? 2 * dp[i - 2][0] : 0)) % MOD;
        }
        return dp[n][0];
    }
};
