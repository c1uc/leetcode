/*
 * @lc app=leetcode id=2017 lang=cpp
 *
 * [2017] Grid Game
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
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        ll pre[n + 1], suff[n + 1], best = LLONG_MAX, cur;

        memset(pre, 0, sizeof(pre));
        memset(suff, 0, sizeof(suff));

        pre[0] = grid[0][0];
        suff[n - 1] = grid[1][n - 1];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + grid[0][i];
            suff[n - i - 1] = suff[n - i] + grid[1][n - i - 1];
        }

        for(int i = 0;i < n;i++) {
            cur = max(pre[n - 1] - pre[i], suff[0] - suff[i]);
            best = min(best, cur);
        }
        return best;
    }
};
// @lc code=end

