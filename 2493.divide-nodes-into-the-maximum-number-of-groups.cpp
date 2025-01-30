/*
 * @lc app=leetcode id=2493 lang=cpp
 *
 * [2493] Divide Nodes Into the Maximum Number of Groups
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector g(n + 1, -1), d(n + 1, 0);
        vector adj(n + 1, vector<int>());
        for(auto edge: edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        int idx = 0;

        auto bfs = [&](int x) -> int {
            vector vis(n + 1, 0);
            queue<int> q;
            q.emplace(x);
            vis[x] = 1;
            int res = 0;

            while(!q.empty()) {
                int u = q.front();
                q.pop();
                res = max(res, vis[u]);
                for(auto v: adj[u]) {
                    if(!vis[v]) {
                        vis[v] = vis[u] + 1;
                        q.emplace(v);
                        g[v] = g[u];
                    }
                    if(abs(vis[u] - vis[v]) != 1) return -1;
                }
            }

            return res;
        };

        for(int i = 1;i <= n;i++) {
            if(g[i] == -1) g[i] = idx++;
            int r = bfs(i);
            if(r == -1) return -1;
            cout << r << endl;
            d[g[i]] = max(d[g[i]], r);
        }

        int ans = 0;
        for(int i = 0;i < idx;i++) ans += d[i];

        return ans;
    }
};
// @lc code=end

