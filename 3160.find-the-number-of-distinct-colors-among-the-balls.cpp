/*
 * @lc app=leetcode id=3160 lang=cpp
 *
 * [3160] Find the Number of Distinct Colors Among the Balls
 */

// @lc code=start
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define n queries.size()
#define x(i) queries[(i)][0]
#define y(i) queries[(i)][1]
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector ans(n, 0);
        unordered_map<int, int> m; 
        unordered_map<int, int> col;
        for(int i = 0;i < n;i++) {
            if(y(i) == col[x(i)]) ans[i] = ans[i - 1];
            else {
                m[col[x(i)]]--;
                ans[i] = (i == 0 ? 0 : ans[i - 1]) + (m[col[x(i)]] == 0 ? -1 : 0) + (m[y(i)] == 0 ? 1 : 0);
                m[col[x(i)] = y(i)]++;
            }
        }
        return ans;
    }
};
// @lc code=end

