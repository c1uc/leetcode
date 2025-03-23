/*
 * @lc app=leetcode id=2965 lang=cpp
 *
 * [2965] Find Missing and Repeated Values
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int r[50 * 50 + 1] = {0};
        for(auto v: grid) {
            for(auto x: v) {
                r[x]++;
            }
        }
        vector<int> ans(2, 0);
        for(int i = 1; i <= grid.size() * grid.size(); i++) {
            if(r[i] == 0) {
                ans[1] = i;
            }
            if(r[i] == 2) {
                ans[0] = i;
            }
        }
        return ans;
    }
};
// @lc code=end

