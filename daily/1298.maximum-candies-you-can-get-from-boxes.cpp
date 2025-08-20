#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
            vector<int> vis(status.size(), 0), has_box(status.size(), 0);
            for(int i : initialBoxes) {
                has_box[i] = 1;
            }
            int ans = 0;
            auto dfs = [&](this auto&& dfs, int u) -> void {
                if(vis[u] || !has_box[u] || !status[u]) return;
                vis[u] = 1;
                ans += candies[u];
                for(int v : keys[u]) {
                    status[v] = 1;
                    if(has_box[v]) dfs(v);
                }
                for(int v : containedBoxes[u]) {
                    has_box[v] = 1;
                    if(status[v]) dfs(v);
                }
            };
            for(int i : initialBoxes) dfs(i);
            return ans;
        }
    };
