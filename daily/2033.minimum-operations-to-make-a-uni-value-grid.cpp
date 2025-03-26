#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int ofs = grid[0][0] % x;
        vector<int> flattened;
        for (auto& row : grid) {
            for (auto& cell : row) {
                if (cell % x != ofs) return -1;
                flattened.emplace_back(cell);
            }
        }
        sort(flattened.begin(), flattened.end());
        int median = flattened[flattened.size() / 2];
        int ans = 0;
        for (auto& cell : flattened) {
            ans += abs(cell - median) / x;
        }
        return ans;
    }
};