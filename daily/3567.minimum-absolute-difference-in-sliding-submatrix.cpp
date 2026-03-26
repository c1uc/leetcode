class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        auto calc = [&](int x, int y) -> int {
            if(k == 1) return 0;
            vector<int> tmp;
            for(int i = x;i < x + k;i++) for(int j = y;j < y + k;j++) tmp.emplace_back(grid[i][j]);
            ranges::sort(tmp, greater<int>());
            int mn = INT_MAX;
            for(int i = 0;i < k * k - 1;i++) if(tmp[i] != tmp[i + 1]) mn = min(tmp[i] - tmp[i + 1], mn);
            return mn == INT_MAX ? 0 : mn;
        };
        int n = grid.size(), m = grid[0].size();
        auto res = vector(n - k + 1, vector<int>(m - k + 1, 0));
        for(int i = 0;i <= n - k;i++) for(int j = 0;j <= m - k;j++) res[i][j] = calc(i, j);
        return res;
    }
};
