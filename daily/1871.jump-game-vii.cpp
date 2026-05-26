class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size(), c = 0;
        vector dp(n, false);
        dp[n - 1] = (s[n - 1] == '0');
        for(int i = n - 2;i >= 0;i--) {
            if(i + minJump < n) c += dp[i + minJump];
            if(i + maxJump + 1 < n) c -= dp[i + maxJump + 1];
            dp[i] = (c > 0) && (s[i] == '0');
        }
        return dp[0];
    }
};
