using ll = long long;

vector<ll> dp(5001, 0);

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        fill(dp.begin(), dp.end(), 0);
        int n = skill.size(), m = mana.size();
        for(int i = 1;i <= m;i++) {
            ll s = 0;
            for(int j = 1;j <= n;j++) {
                dp[0] = max(dp[0], dp[j] - s);
                s += skill[j - 1] * mana[i - 1];
            }
            for(int j = 1;j <= n;j++) {
                dp[j] = max(dp[j], dp[j - 1]) + 1ll * skill[j - 1] * mana[i - 1];
            }
        }
        return dp[n];
    }
};