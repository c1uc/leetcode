using pii = pair<int, int>;
using tii = tuple<int, int, int>;
vector<pii> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        auto val = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        auto bfs = [&]() {
            priority_queue<tii> pq;
            auto vis = vector(n, vector(m, false));
            pq.emplace(health - grid[0][0], 0, 0);
            vis[0][0] = true;
            while(!pq.empty()) {
                auto [h, x, y] = pq.top();
                pq.pop();
                for(auto [dx, dy]: dirs) {
                    int nx = x + dx, ny = y + dy;
                    if(val(nx, ny) && !vis[nx][ny] && h > grid[nx][ny]) {
                        if(nx == n - 1 && ny == m - 1) return true;
                        vis[nx][ny] = true;
                        pq.emplace(h - grid[nx][ny], nx, ny);
                    }
                }
            }
            return false;
        };
        return bfs();
    }
};
