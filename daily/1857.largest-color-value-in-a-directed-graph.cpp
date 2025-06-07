#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> ind(n);
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            ind[edge[1]]++;
        }
        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0) {
                q.push(i);
            }
        }
        int ans = 0;
        int vis = 0;
        while(!q.empty()){
            vis++;
            int u = q.front();
            q.pop();
            dp[u][colors[u] - 'a']++;
            ans = max(ans, dp[u][colors[u] - 'a']);
            for(int v : graph[u]){
                ind[v]--;
                if(ind[v] == 0){
                    q.push(v);
                }
                for(int i = 0; i < 26; i++){
                    dp[v][i] = max(dp[v][i], dp[u][i]);
                }
            }
        }
        if(vis != n){
            return -1;
        }
        return ans;
    }
};
