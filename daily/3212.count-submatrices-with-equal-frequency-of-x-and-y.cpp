const int MAXN = 1001;
bool valid[2][MAXN];
int diff[2][MAXN];

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        memset(valid, false, sizeof(valid));
        memset(diff, 0, sizeof(diff));

        int ans = 0, n = grid.size(), m = grid[0].size();
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                valid[i & 1][j] = (grid[i][j] == 'X') || valid[i & 1 ^ 1][j] || (j ? valid[i & 1][j - 1] : false);
                diff[i & 1][j] = (grid[i][j] == 'X') - (grid[i][j] == 'Y') + diff[i & 1 ^ 1][j] + (j ? diff[i & 1][j - 1] : 0) - (i && j ? diff[i & 1 ^ 1][j - 1] : 0);
                ans += valid[i & 1][j] && (diff[i & 1][j] == 0);
            }
        }
        return ans;
    }
};
