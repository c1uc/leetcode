#include <bits/stdc++.h>
#include <ranges>
using namespace std;


class Solution {
    public:
        int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
            vector<vector<int>> g(n);
            for(auto& h : hierarchy) {
                g[h[0] - 1].push_back(h[1] - 1);
            }
            auto dfs = [&](this auto&& dfs, int x) -> array<vector<int>, 2> {
                vector<int> subtree_res[2] = {vector<int>(budget + 1, INT_MIN / 2), vector<int>(budget + 1, INT_MIN / 2)};
                subtree_res[0][0] = 0;
                subtree_res[1][0] = 0;
                for(int y : g[x]) {
                    auto sub = dfs(y);
                    for(int k = 0;k < 2;k++) {
                        vector<int> new_res(budget + 1, INT_MIN / 2);
                        new_res[0] = 0;
                        for(int c = 0;c <= budget;c++) {
                            int res = subtree_res[k][c];
                            if(res < 0) continue;
                            for(int t = c;t <= budget;t++) {
                                new_res[t] = max(new_res[t], res + sub[k][t - c]);
                            }
                        }
                        subtree_res[k] = new_res;
                    }
                }

                array<vector<int>, 2> res;
                for(int k = 0;k < 2;k++) {
                    res[k] = subtree_res[0];
                    int cost = present[x] / (k + 1);
                    for(int t = cost;t <= budget;t++) {
                        res[k][t] = max(res[k][t], subtree_res[1][t - cost] - cost + future[x]);
                    }
                }
                return res;
            };
            return ranges::max(dfs(0)[0]);
        }
    };
