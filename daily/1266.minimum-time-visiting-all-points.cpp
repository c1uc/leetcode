#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minTimeToVisitAllPoints(vector<vector<int>>& points) {
            int tot = 0, x = points[0][0], y = points[0][1];
            for(auto p: points) {
                int dx = abs(p[0] - x), dy = abs(p[1] - y);
                tot += min(dx, dy) + abs(dx - dy);
                x = p[0];
                y = p[1];
            }
            return tot;
        }
    };
