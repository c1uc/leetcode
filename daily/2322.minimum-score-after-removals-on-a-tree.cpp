#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
            int n = nums.size();
            vector<vector<int>> g(n);
            for(auto& e : edges) {
                g[e[0]].push_back(e[1]);
                g[e[1]].push_back(e[0]);
            }
            vector<int> parent(n), in(n), out(n);
            vector<int> subtree_xor(n);
            int t = 0;
            auto dfs = [&](auto&& self, int u) -> void {
                in[u] = t++;
                subtree_xor[u] = nums[u];
                for(int v : g[u]) {
                    if(v == parent[u]) continue;
                    parent[v] = u;
                    self(self, v);
                    subtree_xor[u] ^= subtree_xor[v];
                }
                out[u] = t;
            };

            parent[0] = -1;
            dfs(dfs, 0);

            int ans = INT_MAX, xor0, xor1, xor2;
            for(int i = 1; i < nums.size() - 1; i++) {
                for(int j = i + 1; j < nums.size(); j++) {
                    if(in[j] > in[i] && in[j] < out[i]) {
                        xor0 = subtree_xor[0] ^ subtree_xor[i];
                        xor1 = subtree_xor[i] ^ subtree_xor[j];
                        xor2 = subtree_xor[j];
                    } else if(in[i] > in[j] && in[i] < out[j]) {
                        xor0 = subtree_xor[0] ^ subtree_xor[j];
                        xor1 = subtree_xor[j] ^ subtree_xor[i];
                        xor2 = subtree_xor[i];
                    } else {
                        xor0 = subtree_xor[0] ^ subtree_xor[i] ^ subtree_xor[j];
                        xor1 = subtree_xor[i];
                        xor2 = subtree_xor[j];
                    }
                    ans = min(ans, max({xor0, xor1, xor2}) - min({xor0, xor1, xor2}));
                }
            }
            return ans;
        }
    };