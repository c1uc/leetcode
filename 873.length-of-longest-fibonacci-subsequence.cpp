/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0;
        unordered_map<int, int> index;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n, 2));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = arr[i];
                int b = arr[j];
                int c = a + b;
                if (index.find(c) != index.end()) {
                    dp[j][index[c]] = dp[i][j] + 1;
                    ans = max(ans, dp[j][index[c]]);
                }
            }
        }

        return ans;
    }
};
// @lc code=end

