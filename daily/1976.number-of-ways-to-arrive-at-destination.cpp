/*
 * @lc app=leetcode id=1976 lang=cpp
 *
 * [1976] Number of Ways to Arrive at Destination
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;

vector<vector<pii>> g(201);
vector<pii> dist(201, {INF, 0});
priority_queue<pii, vector<pii>, greater<pii>> pq;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        fill(g.begin(), g.end(), vector<pii>());
        fill(dist.begin(), dist.end(), pii(INF, 0));
        for(auto &r : roads) {
            g[r[0]].emplace_back(r[1], r[2]);
            g[r[1]].emplace_back(r[0], r[2]);
        }
        
        pq.emplace(0, 0);
        dist[0] = {0, 1};
        while(!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if(d > dist[v].first) continue;
            for(auto [u, w] : g[v]) {
                if(dist[u].first == d + w) {
                    dist[u].second = (dist[u].second + dist[v].second) % MOD;
                } else if(dist[u].first > d + w) {
                    dist[u] = {d + w, dist[v].second % MOD};
                    pq.emplace(d + w, u);
                }
            }
        }
        return dist[n - 1].second;
    }
};
// @lc code=end

