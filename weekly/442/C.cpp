#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll INF = 1e18;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, 0));
        for(int i = 1;i <= m;i++) {
            ll s = 0;
            for(int j = 1;j <= n;j++) {
                dp[i][0] = max(dp[i][0], dp[i - 1][j] - s);
                s += skill[j - 1] * mana[i - 1];
            }
            for(int j = 1;j <= n;j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1ll * skill[j - 1] * mana[i - 1];
            }
        }
        return dp[m][n];
    }
};
