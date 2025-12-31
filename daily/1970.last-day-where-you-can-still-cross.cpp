#include <bits/stdc++.h>
#include <ranges>
using namespace std;
using pii = pair<int, int>;


class Solution {
    public:
        int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
            vector<vector<int>> grid(row, vector<int>(col, 0));
            for(int i = 0;i < cells.size();i++) {
                grid[cells[i][0] - 1][cells[i][1] - 1] = i + 1;
            }
            auto bfs = [&](int t) -> bool {
                queue<pii> q;
                vector<vector<bool>> vis(row, vector<bool>(col, false));
                for(int i = 0;i < col;i++) {
                    if(grid[0][i] > t) q.push({0, i});
                    vis[0][i] = true;
                }
                while(!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    if(x == row - 1) return false;
                    for(auto [dx, dy]: vector<pii>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
                        int nx = x + dx, ny = y + dy;
                        if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] > t && !vis[nx][ny]) {
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                return true;
            };
            return *ranges::lower_bound(views::iota(0, (int)cells.size()), true, {}, bfs) - 1;
        }
    };
