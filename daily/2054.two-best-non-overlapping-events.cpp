#include <bits/stdc++.h>
#include <ranges>
using namespace std;
using tii = tuple<int, int, int>;


class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<tii> t;
        for(auto e: events) {
            t.emplace_back(tii{e[0], 1, e[2]});
            t.emplace_back(tii{e[1] + 1, 0, e[2]});
        }
        ranges::sort(t);
        int mx = 0, ans = 0;
        for(auto p: t) {
            if(get<1>(p)) {
                ans = max(ans, mx + get<2>(p));
            } else {
                mx = max(mx, get<2>(p));
            }
        }
        return ans;
    }
};
