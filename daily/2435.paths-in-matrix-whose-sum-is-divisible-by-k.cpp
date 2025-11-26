#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;


class Solution {
    public:
        int numberOfPaths(vector<vector<int>>& grid, int k) {
            int m = grid.size(), n = grid[0].size();
            vector rem(n, vector<int>(k, 0));
            rem[0][grid[0][0] % k] = 1;
            for(int i = 0;i < m;i++) {
                for(int j = 0;j < n;j++) {
                    if(i == 0 && j == 0) continue;
                    int val = grid[i][j];
                    auto prev_rem = rem[j];
                    for(int r = 0;r < k;r++) {
                        int nr = (r + val) % k;
                        rem[j][nr] = 0;
                        if(j > 0) rem[j][nr] = (rem[j][nr] + rem[j - 1][r]) % MOD;
                        if(i > 0) rem[j][nr] = (rem[j][nr] + prev_rem[r]) % MOD;
                    }
                }
            }
            return rem[n - 1][0];
        }
    };
