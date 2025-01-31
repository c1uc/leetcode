/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector g(n, vector<int>(n, 0));
        vector sz(n * n + 1, 0);
        int idx = 1;

        vector<pii> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        auto dfs = [&](int x, int y, auto self) -> int {
            int res = 1;
            for(auto [dx, dy]: dir) {
                int nx = x + dx, ny = y + dy;
                if(nx < 0 || nx >= n || ny < 0 || ny >= n || !grid[nx][ny] || g[nx][ny]) continue;
                g[nx][ny] = g[x][y];
                res += self(nx, ny, self);
            }
            return res;
        };

        int ans = 0;

        for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) {
            if(!grid[i][j] || g[i][j]) continue;
            g[i][j] = idx++;
            sz[g[i][j]] = dfs(i, j, dfs);
            ans = max(ans, sz[g[i][j]]);
        }

        for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) {
            if(grid[i][j]) continue;
            set<int> iidx;
            int res = 1;
            for(auto [dx, dy]: dir) {
                int nx = i + dx, ny = j + dy;
                if(nx < 0 || nx >= n || ny < 0 || ny >= n || !grid[nx][ny] || iidx.count(g[nx][ny])) continue;
                iidx.insert(g[nx][ny]);
                res += sz[g[nx][ny]];
            }
            ans = max(ans, res);
        }
        
        return ans;
    }
};
// @lc code=end

