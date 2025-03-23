/*
 * @lc app=leetcode id=2685 lang=cpp
 *
 * [2685] Count the Number of Complete Components
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

vector<int> fa(50), sz(50, 1), edges_cnt(50, 0), vis(50, 0);

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        iota(fa.begin(), fa.end(), 0);
        fill(sz.begin(), sz.end(), 1);
        fill(edges_cnt.begin(), edges_cnt.end(), 0);
        fill(vis.begin(), vis.end(), 0);

        auto find = [&](int x, auto &&self) -> int {
            return fa[x] == x ? x : fa[x] = self(fa[x], self);
        };

        for(auto &e: edges) {
            int x = find(e[0], find);
            int y = find(e[1], find);
            if(sz[x] > sz[y]) swap(x, y);
            if(x != y) {
                fa[x] = y;
                sz[y] += sz[x];
                edges_cnt[y] += edges_cnt[x];
            }
            ++edges_cnt[y];
        }

        int ans = 0;
        for(int i = 0;i < n;i++) {
            int x = find(i, find);
            if(vis[x]) continue;
            vis[x] = 1;
            if(sz[x] * (sz[x] - 1) / 2 == edges_cnt[x]) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

