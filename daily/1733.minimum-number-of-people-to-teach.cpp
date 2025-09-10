#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 501;

class Solution {
    public:
        int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
            vector<bitset<MAX_N>> s(MAX_N);
            vector<bool> vis(MAX_N, 0);
            vector<int> k(MAX_N, 0);
            for(int i = 0;i < languages.size();i++) {
                for(int j = 0;j < languages[i].size();j++) {
                    s[i + 1][languages[i][j]] = 1;
                }
            }
            int teach = 0;
            for(int i = 0;i < friendships.size();i++) {
                auto u = friendships[i][0], v = friendships[i][1];
                if((s[u] & s[v]).count() != 0) {
                    continue;
                }
                if(!vis[u]) {
                    teach++;
                    vis[u] = 1;
                    for(auto l: languages[u - 1]) {
                        k[l]++;
                    }
                }
                if(!vis[v]) {
                    teach++;
                    vis[v] = 1;
                    for(auto l: languages[v - 1]) {
                        k[l]++;
                    }
                }
            }
            int ans = 0;
            for(int i = 1;i <= n;i++) {
                ans = max(ans, k[i]);
            }
            return teach - ans;
        }
    };
