using pii = pair<int, int>;
const int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<pii> dp(n, pii{0, 0});
        for(const auto& r: board | views::reverse) {
            vector<pii> dp1(n);
            for(auto [i, v]: r | views::reverse | views::enumerate) {
                if(v == 'S') {
                    dp1[i] = {0, 1};
                    continue;
                }
                if(v == 'X') {
                    dp1[i] = {0, 0};
                    continue;
                }
                int mx = dp[i].first, c = 0;
                if(i) {
                    mx = max({mx, dp[i - 1].first, dp1[i - 1].first});
                    if(mx == dp[i - 1].first) c += dp[i - 1].second;
                    if(mx == dp1[i - 1].first) c += dp1[i - 1].second;
                }
                if(mx == dp[i].first) c += dp[i].second;
                dp1[i] = {mx + (v != 'E' ? v - '0' : 0), c % MOD};
            }
            dp = move(dp1);
        }
        return {dp[n - 1].second == 0 ? 0 : dp[n - 1].first, dp[n - 1].second};
    }
};
