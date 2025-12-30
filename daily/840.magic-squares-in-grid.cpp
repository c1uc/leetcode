#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int numMagicSquaresInside(vector<vector<int>>& grid) {
            auto chk = [&](int x, int y) -> bool {
                int bs = 0;
                for(int i = 0;i < 3;i++) {
                    for(int j = 0;j < 3;j++) {
                        if(grid[x + i][y + j] < 1 || grid[x + i][y + j] > 9) return false;
                        bs |= 1 << (grid[x + i][y + j] - 1);
                    }
                }
                if(bs != (1 << 9) - 1) return false;
                for(int i = 0;i < 3;i++) {
                    int s = 0;
                    for(int j = 0;j < 3;j++) {
                        s += grid[x + i][y + j];
                    }
                    if(s != 15) return false;
                }
                for(int j = 0;j < 3;j++) {
                    int s = 0;
                    for(int i = 0;i < 3;i++) {
                        s += grid[x + i][y + j];
                    }
                    if(s != 15) return false;
                }
                int s = grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2];
                if(s != 15) return false;
                s = grid[x][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y];
                if(s != 15) return false;
                return true;
            };
            if(grid.size() < 3 || grid[0].size() < 3) return 0;
            int ans = 0;
            for(int i = 0;i < grid.size() - 2;i++) {
                for(int j = 0;j < grid[0].size() - 2;j++) {
                    if(chk(i, j)) ans++;
                }
            }
            return ans;
        }
    };
