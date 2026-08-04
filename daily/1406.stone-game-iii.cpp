class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector dp(n + 1, 0);
        for(int i = n - 1;i >= 0;i--) {
            dp[i] = max({
                stoneValue[i] - dp[i + 1],
                i + 2 <= n ? stoneValue[i] + stoneValue[i + 1] - dp[i + 2] : INT_MIN,
                i + 3 <= n ? stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3] : INT_MIN
            });
        }
        return dp[0] > 0 ? "Alice" : dp[0] < 0 ? "Bob" : "Tie";
    }
};
