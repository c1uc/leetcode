#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
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
            vector<int> c1(n), c2(m);
            auto dfs = [&](this auto&& dfs, int u, int p, int tar, vector<vector<int>>& g) -> int {
                if(tar < 0) return 0;
                if(tar == 0) return 1;
                int cnt = 0;
                for (int v : g[u]) {
                    if (v == p) continue;
                    cnt += dfs(v, u, tar - 1, g);
                }
                return cnt + 1;
            };
            for (int i = 0; i < n; i++) {
                c1[i] = dfs(i, -1, k, g1);
            }
            for (int i = 0; i < m; i++) {
                c2[i] = dfs(i, -1, k - 1, g2);
            }
            int max_c2 = *max_element(c2.begin(), c2.end());
            vector<int> ans(n);
            for (int i = 0; i < n; i++) {
                ans[i] = c1[i] + max_c2;
            }

            return ans;
        }
    };
