#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            int n = heights.size(), m = heights[0].size();
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            vector<vector<bool>> pacific(n, vector<bool>(m, false));
            vector<vector<bool>> atlantic(n, vector<bool>(m, false));
            auto dfs = [&](this auto&& dfs, int i, int j, int isPacific) -> void {
                if(isPacific) pacific[i][j] = true;
                else atlantic[i][j] = true;
                visited[i][j] = true;
                pii dir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for(auto [dx, dy]: dir) {
                    int x = i + dx, y = j + dy;
                    if(x >= 0 && x < n && y >= 0 && y < m && heights[x][y] >= heights[i][j] && !visited[x][y]) {
                        dfs(x, y, isPacific);
                    }
                }
            };
            for(int i = 0; i < n; i++) {
                dfs(i, 0, 1);
            }
            for(int j = 0; j < m; j++) {
                dfs(0, j, 1);
            }
            fill(visited.begin(), visited.end(), vector<bool>(m, false));
            for(int i = 0; i < n; i++) {
                dfs(i, m - 1, 0);
            }
            for(int j = 0; j < m; j++) {
                dfs(n - 1, j, 0);
            }
            vector<vector<int>> ans;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(pacific[i][j] && atlantic[i][j]) {
                        ans.push_back({i, j});
                    }
                }
            }
            return ans;
        }
    };
