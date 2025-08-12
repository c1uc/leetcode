#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;

vector<vector<int>> powers(301, vector<int>(5, 301));

auto init = []() {
    for (int i = 0; i < 301; i++) {
        for (int j = 0; j < 5; j++) {
            powers[i][j] = pow(i, j);
            if (powers[i][j] > 300) {
                break;
            }
        }
    }
    return 0;
}();

class Solution {
    public:
        int numberOfWays(int n, int x) {
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            for(int i = n;i >= 1;i--) {
                if(powers[i][x] > n) continue;
                for(int j = n;j >= powers[i][x];j--) {
                    dp[j] = (dp[j] + dp[j - powers[i][x]]) % MOD;
                }
            }
            return dp[n];
        }
    };
