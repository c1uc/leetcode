#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int minimumSum(vector<vector<int>>& grid) {
            auto calc = [&](int up, int down, int left, int right) {
                int r = left, l = right, u = down, d = up;
                for(int i = up; i <= down; i++) {
                    for(int j = left; j <= right; j++) {
                        if(grid[i][j] == 1) {
                            r = max(r, j);
                            l = min(l, j);
                            u = min(u, i);
                            d = max(d, i);
                        }
                    }
                }
                if(l > r || u > d) return 31 * 31;
                return (r - l + 1) * (d - u + 1);
            };

            auto solve = [&](vector<vector<int>>& grid) {
                int n = grid.size();
                int m = grid[0].size();
                int ans = INT_MAX;
                if(n >= 3) {
                    for(int i = 0;i < n - 2;i++) {
                        for(int j = i + 1;j < n - 1;j++) {
                            ans = min(ans, calc(0, i, 0, m - 1) + calc(i + 1, j, 0, m - 1) + calc(j + 1, n - 1, 0, m - 1));
                        }
                    }
                }
                if(n >= 2 && m >= 2) {
                    for(int i = 0;i < n - 1;i++) {
                        for(int j = 0;j < m - 1;j++) {
                            ans = min(ans, calc(0, i, 0, m - 1) + calc(i + 1, n - 1, 0, j) + calc(i + 1, n - 1, j + 1, m - 1));
                        }
                    }
                    for(int i = 1;i < n;i++) {
                        for(int j = 0;j < m - 1;j++) {
                            ans = min(ans, calc(0, i - 1, 0, j) + calc(0, i - 1, j + 1, m - 1) + calc(i, n - 1, 0, m - 1));
                        }
                    }
                }
                return ans;
            };

            auto transpose = [&](vector<vector<int>>& grid) -> vector<vector<int>> {
                int n = grid.size();
                int m = grid[0].size();
                vector<vector<int>> ans(m, vector<int>(n));
                for(int i = 0;i < n;i++) {
                    for(int j = 0;j < m;j++) {
                        ans[j][i] = grid[i][j];
                    }
                }
                return ans;
            };

            int ans = solve(grid);
            grid = transpose(grid);
            ans = min(ans, solve(grid));
            return ans;
        }
    };
