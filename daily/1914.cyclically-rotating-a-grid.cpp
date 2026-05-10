struct pos {
    int x, y;
};

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        auto res = vector(n, vector(m, 0));

        auto rot = [](int x, int layer, int l1, int l2, int k) -> pos {
            int r = (l1 + l2) << 1;
            x = (x + k) % r;
            if(x < l1) {
                return {layer + x, layer};
            }
            x -= l1;
            if(x < l2) {
                return {layer + l1, layer + x};
            }
            x -= l2;
            if(x < l1) {
                return {layer + l1 - x, layer + l2};
            }
            x -= l1;
            return {layer, layer + l2 - x};
        };

        for(int layer = 0;layer < min(n, m) / 2;layer++) {
            int l1 = n - 1 - 2 * layer, l2 = m - 1 - 2 * layer;
            int r = (l1 + l2) << 1;
            for(int i  = 0;i < r;i++) {
                auto cur = rot(i, layer, l1, l2, 0);
                auto nxt = rot(i, layer, l1, l2, k);
                res[nxt.x][nxt.y] = grid[cur.x][cur.y];
            }
        }
        return res;
    }
};
