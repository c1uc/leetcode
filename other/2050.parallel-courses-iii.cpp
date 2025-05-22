#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indeg(n + 1, 0);
        vector<vector<int>> graph(n + 1);
        for(auto& relation : relations) {
            indeg[relation[1]]++;
            graph[relation[0]].push_back(relation[1]);
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(int i = 1; i <= n; i++) {
            if(indeg[i] == 0) {
                pq.push({time[i - 1], i});
            }
        }
        int t = 0;
        while(!pq.empty()) {
            int u = pq.top().second;
            t = pq.top().first;
            pq.pop();
            for(auto& v : graph[u]) {
                indeg[v]--;
                if(indeg[v] == 0) {
                    pq.push({t + time[v - 1], v});
                }
            }
        }
        return t;
    }
};
