#include <bits/stdc++.h>
using namespace std;

using ll = long long;


class Solution {
    public:
        int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
            vector<vector<int>> g(n);
            for(auto& e : edges) {
                g[e[0]].push_back(e[1]);
                g[e[1]].push_back(e[0]);
            }

            int ans = 0;
            auto dfs = [&](this auto&& dfs, int u, int p) -> void {
                for(int v : g[u]) {
                    if(v == p) continue;
                    dfs(v, u);
                }
                values[u] %= k;
                if(values[u] == 0) ans++;
                else values[p] += values[u];
            };
            dfs(0, -1);
            return ans;
        }
    };
