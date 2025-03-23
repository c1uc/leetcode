/*
 * @lc app=leetcode id=1267 lang=cpp
 *
 * [1267] Count Servers that Communicate
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
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        
        vector c(n, 0), r(m, 0);
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j]) {
                    c[j]++;
                    r[i]++;
                }
            }
        }

        for(int i = 0;i < m;i++) if(r[i] > 1) ans += r[i];
        for(int j = 0;j < n;j++) if(c[j] > 1) ans += c[j];

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] && r[i] > 1 && c[j] > 1) {
                    ans--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

