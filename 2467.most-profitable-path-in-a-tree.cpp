/*
 * @lc app=leetcode id=2467 lang=cpp
 *
 * [2467] Most Profitable Path in a Tree
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>> adj(amount.size());
        for (auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        vector<int> bob_dist(amount.size(), -1);
        vector<int> alice_dist(amount.size(), 0);

        auto dfs = [&](int u, int p, int target, vector<int>& dist, auto&& self) -> int {
            if(u == target) return dist[u] = 0;

            for (int v : adj[u]) {
                if(v == p) continue;

                int res = self(v, u, target, dist, self);
                if(res != -1) {
                    dist[u] = res + 1;
                    return res + 1;
                }
            }
            return -1;
        };

        dfs(0, -1, bob, bob_dist, dfs);

        int ans = -1e8;

        auto dfs_alice = [&](int u, int p, int dist, int cost, auto&& self) -> void {
            if(bob_dist[u] == -1) cost += amount[u];
            else if(bob_dist[u] > dist) cost += amount[u];
            else if(bob_dist[u] == dist) cost += amount[u] / 2;

            if(adj[u].size() == 1 && u != 0) {
                ans = max(ans, cost);
                return;
            }

            for (int v : adj[u]) {
                if(v == p) continue;
                self(v, u, dist + 1, cost, self);
            }
        };

        dfs_alice(0, -1, 0, 0, dfs_alice);

        return ans;
    }
};
// @lc code=end

