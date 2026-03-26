const int MOD = 12345;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        auto suf = vector(n + 1, vector(m + 1, 1));
        suf[n - 1][m - 1] = grid[n - 1][m - 1];
        for(int i = n - 1;i >= 0;i--) {
            suf[i][m - 1] = 1ll * suf[i + 1][0] * (i == n - 1 ? 1 : grid[i + 1][0]) % MOD;
            for(int j = m - 2;j >= 0;j--) {
                suf[i][j] = 1ll * suf[i][j + 1] * grid[i][j + 1] % MOD;
            }
        }

        int pre = 1;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                suf[i][j] = 1ll * suf[i][j] * pre % MOD;
                pre = 1ll * pre * grid[i][j] % MOD;
            }
            suf[i].resize(m);
        }
        suf.resize(n);
        return suf;
    }
};
