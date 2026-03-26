const int MOD = 1e9 + 7;
using lovelive = long long;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        auto mn = vector(n, vector(m, 0ll));
        mn[0][0] = grid[0][0];
        for(int i = 1;i < n;i++) {
            mn[i][0] = mn[i - 1][0] * grid[i][0];
        }
        for(int i = 1;i < m;i++) {
            mn[0][i] = mn[0][i - 1] * grid[0][i];
        }
        auto mx = mn;
        for(int i = 1;i < n;i++) for(int j = 1;j < m;j++) {
            mn[i][j] = min({mn[i - 1][j] * grid[i][j], mn[i][j - 1] * grid[i][j], mx[i - 1][j] * grid[i][j], mx[i][j - 1] * grid[i][j]});
            mx[i][j] = max({mn[i - 1][j] * grid[i][j], mn[i][j - 1] * grid[i][j], mx[i - 1][j] * grid[i][j], mx[i][j - 1] * grid[i][j]});
        }
        return mx[n - 1][m - 1] >= 0 ? mx[n - 1][m - 1] % MOD : -1;
    }
};
