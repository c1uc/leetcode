/*
 * @lc app=leetcode id=2685 lang=cpp
 *
 * [2685] Count the Number of Complete Components
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> fa(n), sz(n, 1), edges_cnt(n, 0), vis(n, 0);
        iota(fa.begin(), fa.end(), 0);

        auto find = [&](int x, auto &&self) -> int {
            return fa[x] == x ? x : fa[x] = self(fa[x], self);
        };

        for(auto &e: edges) {
            int x = find(e[0], find);
            int y = find(e[1], find);
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

