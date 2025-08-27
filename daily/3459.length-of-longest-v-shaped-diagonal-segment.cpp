#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

class Solution {
    public:
        int lenOfVDiagonal(vector<vector<int>>& grid) {
            int n = grid.size(), m = grid[0].size();
            auto memo = vector<vector<vector<vector<int>>>>(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(2, -1))));
            auto dirs = vector<pii>{{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

            auto dfs = [&](this auto&& dfs, int i, int j, int dir, int can_turn, int target) -> int {
                if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != target) return 0;
                if(memo[i][j][dir][can_turn] != -1) return memo[i][j][dir][can_turn];

                int res = dfs(i + dirs[dir].first, j + dirs[dir].second, dir, can_turn, 2 - grid[i][j]);
                if(can_turn) {
                    int ndir = (dir + 1) % 4;
                    res = max(res, dfs(i + dirs[ndir].first, j + dirs[ndir].second, ndir, 0, 2 - grid[i][j]));
                }
                
                return memo[i][j][dir][can_turn] = res + 1;
            };

            int ans = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] != 1) continue;
                    for(int k = 0; k < 4; k++) {
                        ans = max(ans, dfs(i + dirs[k].first, j + dirs[k].second, k, 1, 2) + 1);
                    }
                }
            }
            return ans;
        }
    };
