class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        auto res = vector(m, vector(n, 0));
        for(auto [i, row]: grid | views::enumerate) for(auto [j, x]: row | views::enumerate) {
            res[(i + (j + k) / n) % m][(j + k) % n] = x;
        }
        return res;
    }
};
