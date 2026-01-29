#include <bits/stdc++.h>
using namespace std;

constexpr long long INF = 1e18;

class Solution {
    public:
        long long minimumCost(string src, string tar, vector<char>& from, vector<char>& to, vector<int>& cost) {
            vector<vector<long long>> dist(26, vector<long long>(26, INF));
            for(int i = 0;i < from.size();i++) {
                dist[from[i] - 'a'][to[i] - 'a'] = min(dist[from[i] - 'a'][to[i] - 'a'], 1ll * cost[i]);
            }
            for(int i = 0;i < 26;i++) {
                dist[i][i] = 0;
            }
            for(int k = 0;k < 26;k++) {
                for(int i = 0;i < 26;i++) {
                    for(int j = 0;j < 26;j++) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
            long long ans = 0;
            for(int i = 0;i < src.size();i++) {
                if(dist[src[i] - 'a'][tar[i] - 'a'] == INF) return -1;
                ans += dist[src[i] - 'a'][tar[i] - 'a'];
            }
            return ans;
        }
    };
