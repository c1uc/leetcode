const int MAXN = 1e5 + 1;

bool dp[MAXN] = {false};

auto init = []() {
    for(int i = 0;i < MAXN;i++) {
        if(dp[i]) continue;
        for(int k = 1;i + k * k < MAXN;k++) {
            dp[i + k * k] = true;
        }
    }
    return 'c';
}();

class Solution {
public:
    bool winnerSquareGame(int n) {
        return dp[n];
    }
};
