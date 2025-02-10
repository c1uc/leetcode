/*
 * @lc app=leetcode id=3174 lang=cpp
 *
 * [3174] Clear Digits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(char c: s) {
            if(c >= '0' && c <= '9') {
                st.pop();
            } else {
                st.push(c);
            }
        }
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

