/*
 * @lc app=leetcode id=3108 lang=cpp
 *
 * [3108] Minimum Cost Walk in Weighted Graph
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define MAXN 0xffffff

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> pa(n);
        iota(pa.begin(), pa.end(), 0);
        vector<int> cost(n, MAXN);
        vector<int> res(query.size());

        auto find = [&](int x, auto self) -> int {
            return x == pa[x] ? x : pa[x] = self(pa[x], self);
        };

        auto unite = [&](int x, int y, int w) {
            x = find(x, find);
            y = find(y, find);
            if(x != y) {
                pa[x] = y;
                cost[y] = cost[y] & cost[x] & w;
            } else {
                cost[x] &= w;
            }
        };

        for(auto& e: edges) {
            unite(e[0], e[1], e[2]);
        }

        for(int i = 0;i < query.size();i++) {
            int x = find(query[i][0], find);
            int y = find(query[i][1], find);
            res[i] = x == y ? cost[x] : -1;
        }
        return res;
    }
};
// @lc code=end

