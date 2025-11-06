#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
            vector<int> label(c + 1, -1), ok(c + 1, 1);
            vector<vector<int>> g(c + 1);
            vector<set<int>> groups;
            int idx = 0;
            for(auto& conn : connections) {
                g[conn[0]].push_back(conn[1]);
                g[conn[1]].push_back(conn[0]);
            }
            auto dfs = [&](this auto&& dfs, int u) -> void {
                for(int v : g[u]) {
                    if(label[v] != -1) continue;
                    label[v] = label[u];
                    groups[label[u]].insert(v);
                    dfs(v);
                }
            };
            for(int i = 1; i <= c; i++) {
                if(label[i] == -1) {
                    label[i] = idx++;
                    groups.push_back({i});
                    dfs(i);
                }
            }
            vector<int> ans;
            for(auto& q : queries) {
                int i = label[q[1]];
                if(q[0] == 1) {
                    if(ok[q[1]]) ans.emplace_back(q[1]);
                    else ans.emplace_back(groups[i].size() > 0 ? *groups[i].begin() : -1);
                } else {
                    groups[i].erase(q[1]);
                    ok[q[1]] = 0;
                }
            }
            return ans;
        }
    };