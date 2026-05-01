typedef pair<int, int> pii;
const vector<pii> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size();
        auto vis = vector(m, vector(n, false));
        auto dfs = [&](this auto&& dfs, int x, int y, int a, int b) -> bool {
            if(vis[x][y]) return false;
            vis[x][y] = true;
            for(const auto& d: dir) {
                auto nx = x + d.first, ny = y + d.second;
                if(nx == a && ny == b) continue;
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || g[nx][ny] != g[x][y]) continue;
                if(vis[nx][ny]) return true;
                if(dfs(nx, ny, x, y)) return true;
            }
            return false;
        };
        return ranges::any_of(views::cartesian_product(views::iota(0, m), views::iota(0, n)), [&](auto p) {return dfs(get<0>(p), get<1>(p), -1, -1);});
    }
};
