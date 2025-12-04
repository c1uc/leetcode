#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int countTrapezoids(vector<vector<int>>& points) {
            unordered_map<double, map<double, int>> slope_intercept_count;
            unordered_map<int, map<double, int>> mid_slope_count;
            for(int i = 0; i < points.size(); i++) {
                int x1 = points[i][0], y1 = points[i][1];
                for(int j = i + 1; j < points.size(); j++) {
                    int x2 = points[j][0], y2 = points[j][1];
                    int dx = x2 - x1, dy = y2 - y1;

                    double slope = dx == 0 ? DBL_MAX : (double)dy / dx;
                    double intercept = dx == 0 ? x1 : 1.0 * (y1 * dx - x1 * dy) / dx;
                    slope_intercept_count[slope][intercept]++;

                    int mid = (x1 + x2 + 2000) << 16 | (y1 + y2 + 2000);
                    mid_slope_count[mid][slope]++;
                }
            }
            int ans = 0;
            for(auto &[_, cnt] : slope_intercept_count) {
                int s = 0;
                for(auto &[_, c] : cnt) {
                    ans += s * c;
                    s += c;
                }
            }
            for(auto &[_, cnt] : mid_slope_count) {
                int s = 0;
                for(auto &[_, c] : cnt) {
                    ans -= s * c;
                    s += c;
                }
            }
            return ans;
        }
    };
