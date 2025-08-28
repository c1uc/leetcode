#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
            int n = grid.size(), m = grid[0].size();
            auto d = vector<int>(n + m - 1);
            for(int k = n - 1; k > 0;k--) {
                int idx = 0;
                for(int i = 0, j = k; i < n && j < m; i++, j++) {
                    d[idx++] = grid[i][j];
                }
                sort(d.begin(), d.begin() + idx, greater<int>());
                idx = 0;
                for(int i = 0, j = k; i < n && j < m; i++, j++) {
                    grid[i][j] = d[idx++];
                }
            }
            for(int k = 0; k < m - 1; k++) {
                int idx = 0;
                for(int j = 0, i = k; i < n && j < m; j++, i++) {
                    d[idx++] = grid[i][j];
                }
                sort(d.begin(), d.begin() + idx, less<int>());
                idx = 0;
                for(int j = 0, i = k; i < n && j < m; j++, i++) {
                    grid[i][j] = d[idx++];
                }
            }
            return grid;
        }
    };
