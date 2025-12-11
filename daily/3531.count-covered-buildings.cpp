#include <bits/stdc++.h>
using namespace std;


using pii = pair<int, int>;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pii> xs, ys;
        for(auto b: buildings) {
            int x = b[0], y = b[1];
            if(xs.find(y) != xs.end()) {
                auto& it = xs[y];
                it.first = min(x, it.first);
                it.second = max(x, it.second);
            } else {
                xs[y] = {x, x};
            }
            if(ys.find(x) != ys.end()) {
                auto& it = ys[x];
                it.first = min(y, it.first);
                it.second = max(y, it.second);
            } else {
                ys[x] = {y, y};
            }
        }
        int ans = 0;
        for(auto b: buildings) {
            int x = b[0], y = b[1];
            if(x > xs[y].first && x < xs[y].second && y > ys[x].first && y < ys[x].second) ans++;
        }
        return ans;
    }
};
