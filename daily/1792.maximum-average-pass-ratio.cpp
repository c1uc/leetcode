#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;


class Solution {
    public:
        double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

            auto calc = [&](const pii& a) {
                return 1.0 * (a.first + 1) / (a.second + 1) - 1.0 * a.first / a.second + 1e-6;
            };

            auto cmp = [&](const pii& a, const pii& b) {
                return calc(a) > calc(b);
            };

            priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
            for(auto& c : classes) {
                pq.emplace(c[0], c[1]);
            }

            while(extraStudents-- && !pq.empty() && calc(pq.top()) < 0) {
                auto [pass, total] = pq.top(); pq.pop();
                pq.emplace(pass + 1, total + 1);
            }
            double ans = 0;
            while(!pq.empty()) {
                auto [pass, total] = pq.top();
                pq.pop();
                ans += pass / total;
            }
            return ans / classes.size();
        }
    };
