/*
 * @lc app=leetcode id=1415 lang=cpp
 *
 * [1415] The k-th Lexicographical String of All Happy Strings of Length n
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        auto dfs = [&](auto&& self, string s) -> string {
            if (s.size() == n) {
                if (--k == 0) return s;
                return "";
            }
            for (char c = 'a'; c <= 'c'; ++c) {
                if (s.empty() || s.back() != c) {
                    string res = self(self, s + c);
                    if (!res.empty()) return res;
                }
            }
            return "";
        };
        return dfs(dfs, "");
    }
};
// @lc code=end

