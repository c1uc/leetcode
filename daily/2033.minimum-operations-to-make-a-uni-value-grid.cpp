#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int ofs = grid[0][0] % x, n = grid.size() * grid[0].size();
        vector<int> flattened;
        for (auto& row : grid) {
            for (auto& cell : row) {
                if (cell % x != ofs) return -1;
                flattened.emplace_back(cell);
            }
        }
        nth_element(flattened.begin(), flattened.begin() + n / 2, flattened.end());
        int median = flattened[n / 2];
        int ans = 0;
        for (auto& cell : flattened) {
            ans += abs(cell - median) / x;
        }
        return ans;
    }
};
