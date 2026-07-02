using pii = pair<int, int>;
vector<pii> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pii> q;
        for(auto [i, v]: grid | views::enumerate) for(auto [j, x]: v | views::enumerate) {
            if(x == 1) {
                q.emplace(i, j);
                x = 0;
            }
            else x = -1;
        }
        int l = 0, r = 0;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(auto [dx, dy]: dirs) {
                int nx = x + dx, ny = y + dy, nd = grid[x][y] + 1;
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == -1) {
                    r = max(r, nd + 1);
                    grid[nx][ny] = nd;
                    q.emplace(nx, ny);
                }
            }
        }
        // for(auto [i, v]: grid | views::enumerate) {
        //     for(auto [j, x]: v | views::enumerate) cout << x << ' ';
        //     cout << endl;
        // }
        auto bfs = [&](int tar) {
            if(grid[0][0] < tar || grid[n - 1][m - 1] < tar) return false;
            if(tar == 0) return true;
            vector<vector<bool>> vis(n, vector(m, false));
            q.emplace(0, 0);
            vis[0][0] = true;
            while(!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for(auto [dx, dy]: dirs) {
                    int nx = x + dx, ny = y + dy;
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] >= tar) {
                        if(nx == n - 1 && ny == m - 1) return true;
                        q.emplace(nx, ny);
                        vis[nx][ny] = true;
                    }
                }
            }
            return false;
        };
        while(l + 1 < r) {
            int mid = (l + r) >> 1;
            while(!q.empty()) q.pop();
            if(bfs(mid)) l = mid;
            else r = mid;
        }
        return l;
    }
};
