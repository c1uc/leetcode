#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int minimumArea(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            int up = n, down = -1, left = m, right = -1;
            for(int i = 0; i < n; i++) {
                if(ranges::any_of(grid[i], [](int x) { return x == 1; })) {
                    up = i;
                    break;
                }
            }
            for(int i = n - 1; i >= 0; i--) {
                if(ranges::any_of(grid[i], [](int x) { return x == 1; })) {
                    down = i;
                    break;
                }
            }
            for(int j = 0; j < m; j++) {
                for(int i = up; i <= down; i++) {
                    if(grid[i][j] == 1) {
                        left = min(left, j);
                        right = max(right, j);
                        break;
                    }
                }
            }
            return (down - up + 1) * (right - left + 1);
        }
    };
