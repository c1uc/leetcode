#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        int ans = 0;
        vector<vector<int>> adj(n + 1);
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        auto dfs = [&](auto&& dfs, int u, int p) -> int {
            if(!adj[u].size()) return cost[u];
            int max_cost = 0, c = 0;
            for(int v : adj[u]) {
                if(v == p) continue;
                int cos = dfs(dfs, v, u);
                if(cos > max_cost) {
                    max_cost = cos;
                    c = 1;
                } else if(cos == max_cost) c++;
            }
            ans += adj[u].size() - c;
            return max_cost + cost[u];
        };
        dfs(dfs, 0, -1);
        return ans;
    }
};

