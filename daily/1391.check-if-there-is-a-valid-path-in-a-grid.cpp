// dirs    0
//       1   3
//         2

int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int dirs[] = {
    0, 0b1010, 0b0101, 0b0110, 0b1100, 0b0011, 0b1001
};

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        auto vis = vector(n, vector(m, false));
        auto dfs = [&](this auto&& dfs, int x, int y) -> bool {
            if(vis[x][y]) return false;
            if(x == n - 1 && y == m - 1) return true;
            vis[x][y] = true;
            int d = dirs[grid[x][y]];
            for(int i = 0;i < 4;i++) if((d >> i) & 1) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                int nd = dirs[grid[nx][ny]];
                if(!((nd >> (i ^ 2)) & 1)) continue;
                if(dfs(nx, ny)) return true;
            }
            return false;
        };
        return dfs(0, 0);
    }
};
