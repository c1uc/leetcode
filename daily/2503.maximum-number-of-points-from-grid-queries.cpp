/*
 * @lc app=leetcode id=2503 lang=cpp
 *
 * [2503] Maximum Number of Points From Grid Queries
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
using tup = tuple<int, int, int>;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(queries.size());
        vector<vector<bool>> vis(m, vector<bool>(n));
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<int> argsort(queries.size());
        iota(argsort.begin(), argsort.end(), 0);
        sort(argsort.begin(), argsort.end(), [&](int i, int j) {
            return queries[i] < queries[j];
        });
        
        int sum = 0, idx = 0;
        priority_queue<tup, vector<tup>, greater<tup>> pq;
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        while (!pq.empty()) {
            auto [val, i, j] = pq.top();
            pq.pop();
            while (idx < queries.size() && queries[argsort[idx]] <= val) {
                ans[argsort[idx++]] = sum;
            }
            if (idx >= queries.size()) {
                break;
            }
            ++sum;
            for (auto [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                    pq.push({grid[x][y], x, y});
                    vis[x][y] = true;
                }
            }
        }
        while (idx < queries.size()) {
            ans[argsort[idx++]] = sum;
        }
        return ans;
    }
};
// @lc code=end

