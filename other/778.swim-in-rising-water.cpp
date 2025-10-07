#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int swimInWater(vector<vector<int>>& grid) {
            int n = grid.size(), m = grid[0].size();
            vector<vector<bool>> vis(n, vector<bool>(m));
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            pq.push({grid[0][0], 0 * m + 0});
            vis[0][0] = true;
            int ans = 0;
            while(!pq.empty()) {
                auto [d, p] = pq.top();
                pq.pop();
                ans = max(ans, d);
                if(p == n * m - 1) return ans;
                for(auto [dx, dy]: vector<pii>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
                    int x = p / m + dx, y = p % m + dy;
                    if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]) {
                        vis[x][y] = true;
                        vis[x][y] = true;
                        pq.push({grid[x][y], x * m + y});
                    }
                }
            }
            return ans;
        }
    };
