#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pii>> g(n, vector<pii>());
        for(auto x: edges) {
            int u = x[0], v = x[1], w = x[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, 2 * w);
        }
        vector<int> vis(n, -1);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [t, x] = pq.top();
            pq.pop();

            for(auto [y, w]: g[x]) {
                if(t + w < vis[y] || vis[y] == -1) {
                    vis[y] = t + w;
                    pq.push({t + w, y});
                }
            }
        }
        return vis[n - 1];
    }
};
