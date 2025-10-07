#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
            vector<vector<int>> g(n);
            for(auto& e : edges) {
                g[e[0]].push_back(e[1]);
            }
            vector<int> pre(n, 0);
            for(auto& e : edges) {
                pre[e[1]] |= (1 << e[0]);
            }
            vector<int> dp(1 << n, -1);
            dp[0] = 0;
            for(int i = 0; i < (1 << n); i++) {
                if(dp[i] == -1) continue;
                for(int j = 0; j < n; j++) {
                    if(i & (1 << j)) continue;
                    if((i & pre[j]) != pre[j]) continue;
                    int c = popcount(i);
                    dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + score[j] * (c + 1));
                }
            }
            return dp[(1 << n) - 1];
        }
    };
