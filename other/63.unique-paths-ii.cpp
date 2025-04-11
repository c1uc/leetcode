/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector dp(n, 0);
        
        for(int i = 0; i < n; i++) {
            if(!obstacleGrid[0][i]) {
                dp[i] = 1;
            } else {
                break;
            }
        }

        for(int i = 1; i < m; i++) {
            dp[0] = !obstacleGrid[i][0] * dp[0];
            for(int j = 1; j < n; j++) {
                if(!obstacleGrid[i][j]) {
                    dp[j] += dp[j - 1];
                } else {
                    dp[j] = 0;
                }
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end

