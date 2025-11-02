#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
            vector<vector<int>> vis(m, vector<int>(n, 0));
            for(auto& g: guards) {
                vis[g[0]][g[1]] = 1;
            }
            for(auto& w: walls) {
                vis[w[0]][w[1]] = -1;
            }
            for(auto& g: guards) {
                int x = g[0], y = g[1];
                if(vis[x][y] & 2) continue;
                for(int i = x + 1;i < m;i++) {
                    if(vis[i][y] == -1) break;
                    vis[i][y] |= 2;
                }
                for(int i = x - 1;i >= 0;i--) {
                    if(vis[i][y] == -1) break;
                    vis[i][y] |= 2;
                }
            }
            for(auto& g: guards) {
                int x = g[0], y = g[1];
                if(vis[x][y] & 4) continue;
                for(int i = y + 1;i < n;i++) {
                    if(vis[x][i] == -1) break;
                    vis[x][i] |= 4;
                }
                for(int i = y - 1;i >= 0;i--) {
                    if(vis[x][i] == -1) break;
                    vis[x][i] |= 4;
                }
            }
            int ans = 0;
            for(int i = 0;i < m;i++) {
                for(int j = 0;j < n;j++) {
                    if(vis[i][j] == 0) ans++;
                }
            }
            return ans;
        }
    };