class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector diag(2, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                diag[0][i + 1][j + 1] = diag[0][i][j] + grid[i][j];
            }
        }
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                diag[1][i + 1][j + 1] = diag[1][i][j] + grid[i][n - j - 1];
            }
        }

        for(int i = 0;i <= m;i++) {
            for(int j = 0;j <= n;j++) {
                cout << diag[1][i][j] << ' ';
            }
            cout << endl;
        }
        
        vector<int> res = {-INT_MAX, -INT_MAX, -INT_MAX};
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                for(int l = 0;;l++) {
                    if(i + 2 * l >= m || j + l >= n || j - l < 0) break;
                    int r;
                    if(l == 0) r = grid[i][j];
                    else {
                        int s1 = diag[0][i + l + 1][j + l + 1] + diag[1][i + l + 1][n - j + l] - diag[0][i][j] - diag[1][i][n - j - 1];
                        int s2 = diag[0][i + 2 * l + 1][j + 1] + diag[1][i + 2 * l + 1][n - j] - diag[0][i + l][j - l] - diag[1][i + l][n - j - l - 1];
                        r = s1 + s2 - grid[i][j] - grid[i + 2 * l][j] - grid[i + l][j + l] - grid[i + l][j - l];
                    }
                    if(r == res[0] || r == res[1] || r == res[2]) continue;
                    if(r > res[0]) {
                        res[2] = res[1];
                        res[1] = res[0];
                        res[0] = r;
                    } else if(r > res[1]) {
                        res[2] = res[1];
                        res[1] = r;
                    } else if(r > res[2]) {
                        res[2] = r;
                    }
                }
            }
        }
        return res | views::filter( [](int x) {return x != -INT_MAX;} ) | ranges::to<vector<int>>();
    }
};
