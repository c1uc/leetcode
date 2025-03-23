#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
        int vis[m * n];
        memset(vis, 0, sizeof(vis));

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int res = m * n;
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            if(u == m * n - 1) return d;

            pq.pop();
            
            if(vis[u]) continue;
            vis[u] = 1;
            int x = u / n, y = u % n;
            for(int k = 0;k < 4;k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int v = nx * n + ny;
                    if(!vis[v]) pq.push({d + !(grid[x][y] == k + 1), v});
                }
            }
        }
        return -1;
    }
};


signed main() {_

    return 0;
}
