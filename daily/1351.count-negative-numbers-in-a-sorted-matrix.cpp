#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int countNegatives(vector<vector<int>>& grid) {
            int n = grid.size(), m = grid[0].size();
            int c = m - 1, ans = 0;
            for(int r = 0;r < n;r++) {
                while(c >= 0 && grid[r][c] < 0) c--;
                ans += m - c - 1;
            }
            return ans;
        }
    };