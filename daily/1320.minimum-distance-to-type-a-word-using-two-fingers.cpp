auto dist = [](int a, int b) {
    return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
};

class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        vector<array<int, 26>> dp(n);
        for(int i = 0;i < n - 1;i++) {
            int c1 = word[i] - 'A', c2 = word[i + 1] - 'A';
            for(int ch = 0;ch < 26;ch++) {
                dp[i + 1][ch] = min(dp[i][ch] + dist(c1, c2), dp[i][c2] + dist(c1, ch));
            }
        }
        return ranges::min(dp[n - 1]);
    }
};
