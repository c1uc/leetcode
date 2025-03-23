/*
 * @lc app=leetcode id=2658 lang=cpp
 *
 * [2658] Maximum Number of Fish in a Grid
 */

// @lc code=start
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll INF = 1e18;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        vector<pii> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector vis(grid.size(), vector<bool>(grid[0].size(), false));

        auto dfs = [&](pii x, auto self) -> int {
            vis[x.first][x.second] = true;
            int res = 0;
            for(auto [dx, dy]: dir) {
                int nx = x.first + dx, ny = x.second + dy;
                if(nx >= 0 && nx < vis.size() && ny >= 0 && ny < vis[0].size() && !vis[nx][ny] && grid[nx][ny]) res += self({nx, ny}, self);
            }
            return res + grid[x.first][x.second];
        };

        int ans = 0;
        for(int i = 0;i < vis.size();i++) for(int j = 0;j < vis[0].size();j++) {
            if(!vis[i][j] && grid[i][j]) ans = max(ans, dfs({i, j}, dfs));
        }
        return ans;
    }
};
// @lc code=end

