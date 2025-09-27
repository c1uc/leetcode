#include <bits/stdc++.h>
#include <ranges>
using namespace std;


class Solution {
    using pii = pair<int, int>;
    public:
        double largestTriangleArea(vector<vector<int>>& points) {
            auto cross = [](pii o, pii a, pii b) {
                return (a.first - o.first) * (b.second - o.second) - (a.second - o.second) * (b.first - o.first);
            };
            auto calc = [&](pii a, pii b, pii c) {
                return abs(cross(a, b, c)) / 2.0;
            };
            sort(points.begin(), points.end(), less<>());
            
            vector<pii> p;
            int t = 0;
            for(auto &x : points) {
                while(t > 1 && cross(p[t - 2], p[t - 1], {x[0], x[1]}) <= 0) {
                    t--;
                    p.pop_back();
                }
                p.push_back({x[0], x[1]});
                t++;
            }
            int u = t + 1;
            for(auto &x : points | views::reverse | views::drop(1)) {
                while(t >= u && cross(p[t - 2], p[t - 1], {x[0], x[1]}) <= 0) {
                    t--;
                    p.pop_back();
                }
                p.push_back({x[0], x[1]});
                t++;
            }
            if(p.size() > 1) p.pop_back();

            double ans = 0;
            for(int i = 0; i < p.size(); i++) {
                int k = i + 2;
                for(int j = i + 1; j < p.size(); j++) {
                    while(k + 1 < p.size() && calc(p[i], p[j], p[k]) < calc(p[i], p[j], p[k + 1])) {
                        k++;
                    }
                    ans = max(ans, calc(p[i], p[j], p[k % p.size()]));
                }
            }
            return ans;
        }
    };
