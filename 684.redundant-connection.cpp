/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll INF = 1e18;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector fa(edges.size() + 1, 0), sz(edges.size() + 1, 1);
        iota(fa.begin(), fa.end(), 0);

        auto find = [&](int x, auto self) -> int {
            if(fa[x] == x) return x;
            return fa[x] = self(fa[x], self);
        };

        auto un = [&](int x, int y) {
            x = find(x, find);
            y = find(y, find);
            if(sz[x] > sz[y]) swap(x, y);
            fa[x] = y;
            sz[y] += sz[x];
        };

        for(auto edge: edges) {
            int u = edge[0], v = edge[1];
            if(find(u, find) != find(v, find)) {
                un(u, v);
            }
            else {
                return edge;
            }
        }
        return *edges.rbegin();
    }
};
// @lc code=end

