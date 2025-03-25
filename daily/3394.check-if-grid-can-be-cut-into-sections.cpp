/*
 * @lc app=leetcode id=3394 lang=cpp
 *
 * [3394] Check if Grid can be Cut into Sections
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        auto cmp1 = [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        };
        auto cmp2 = [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
        };

        sort(rectangles.begin(), rectangles.end(), cmp1);
        int cur = rectangles[0][2], c = 0;
        for(int i = 1; i < rectangles.size(); i++) {
            if(rectangles[i][0] >= cur)  c++;
            cur = max(cur, rectangles[i][2]);
        }
        if(c > 1) return true;

        sort(rectangles.begin(), rectangles.end(), cmp2);
        cur = rectangles[0][3], c = 0;
        for(int i = 1; i < rectangles.size(); i++) {
            if(rectangles[i][1] >= cur)  c++;
            cur = max(cur, rectangles[i][3]);
        }
        return c > 1;
    }
};
// @lc code=end

