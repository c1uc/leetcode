class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0, r = m;
        for(int row = 0;row < n;row++) {
            for(int c = 0;c < m;c++) grid[row][c] += (c ? grid[row][c - 1] : 0) + (row ? grid[row - 1][c] : 0) - (row && c ? grid[row - 1][c - 1] : 0);
            while(r > 0 && grid[row][r - 1] > k) r--;
            ans += r;
        }
        return ans;
    }
};
