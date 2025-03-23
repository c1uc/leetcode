/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll INF = 1e18;

void dfs(int x, vector<vector<int>>& edge, vector<int>& in_cnt, vector<int>& out_deg) {
    for(auto j: edge[x]) {
        in_cnt[j]++;
        if(in_cnt[j] == out_deg[j])
            dfs(j, edge, in_cnt, out_deg);
    }
}

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector edge(graph.size(), vector<int>());
        vector out_deg(graph.size(), 0), in_cnt(graph.size(), 0);
        vector vis(graph.size(), false);

        for(int i = 0;i < graph.size();i++) {
            for(auto& j: graph[i]) {
                out_deg[i]++;
                edge[j].emplace_back(i);
            }
        }

        for(int i = 0;i < graph.size();i++) if(out_deg[i] == 0) dfs(i, edge, in_cnt, out_deg);

        vector<int> ans;
        for(int i = 0;i < graph.size();i++) if(out_deg[i] == in_cnt[i]) ans.emplace_back(i);
        return ans;
    }
};
// @lc code=end

