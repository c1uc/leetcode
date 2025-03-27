/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        auto f = [&](this auto&& f, int c, int l, string s) -> void {
            if(l == 2 * n && c == 0) {
                res.push_back(s);
                return;
            }
            if(c > 0) {
                f(c - 1, l + 1, s + ')');
            }
            f(c + 1, l + 1, s + '(');
        };
        f(0, 0, "");
        return res;
    }
};
// @lc code=end

