#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

class Solution {
    public:
        vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
            vector<int> timestamp(n, -1);
            vector<vector<pii>> g(n);
            sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b) {
                return a[2] < b[2];
            });
            g[0].emplace_back(firstPerson, 0);
            for(auto& meeting : meetings) {
                g[meeting[0]].emplace_back(meeting[1], meeting[2]);
                g[meeting[1]].emplace_back(meeting[0], meeting[2]);
            }
            timestamp[0] = 0;
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            pq.emplace(0, 0);
            while(!pq.empty()) {
                auto [t, u] = pq.top();
                pq.pop();
                if(timestamp[u] != -1) continue;
                timestamp[u] = t;
                for(auto& [v, tt] : g[u]) {
                    if(timestamp[v] != -1 || tt < t) continue;
                    pq.emplace(tt, v);
                }
            }
            vector<int> ans;
            for(int i = 0;i < n;i++) {
                if(timestamp[i] != -1) ans.push_back(i);
            }
            return ans;
        }
    };
