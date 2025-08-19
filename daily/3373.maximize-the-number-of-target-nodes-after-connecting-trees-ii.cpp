#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
            int n = edges1.size() + 1, m = edges2.size() + 1;
            vector<vector<int>> g1(n), g2(m);
            for (auto& e : edges1) {
                g1[e[0]].push_back(e[1]);
                g1[e[1]].push_back(e[0]);
            }
            for (auto& e : edges2) {
                g2[e[0]].push_back(e[1]);
                g2[e[1]].push_back(e[0]);
            }
            vector<int> color1(n, -1), color2(m, -1);
            auto dfs = [&](this auto&& dfs, int u, int p, int c, vector<vector<int>>& g, vector<int>& color) {
                color[u] = c;
                for (int v : g[u]) {
                    if (v == p) continue;
                    dfs(v, u, !c, g, color);
                }
            };
            for (int i = 0; i < n; i++) {
                dfs(i, -1, 0, g1, color1);
            }
            for (int i = 0; i < m; i++) {
                dfs(i, -1, 0, g2, color2);
            }
            int odd1 = count(color1.begin(), color1.end(), 1), odd2 = count(color2.begin(), color2.end(), 1);
            int num = max(odd2, m - odd2);
            vector<int> ans(n);
            for(int i = 0; i < n; i++) {
                ans[i] = (color1[i] == 1 ? odd1 : n - odd1) + num;
            }
            return ans;
        }
    };
