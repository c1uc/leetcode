/*
 * @lc app=leetcode id=1790 lang=cpp
 *
 * [1790] Check if One String Swap Can Make Strings Equal
 */

// @lc code=start
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        short c = 0;
        short a[2], b[2];
        for(int i = 0;i < s1.size();i++) {
            if(s1[i] == s2[i]) continue;
            if(c == 2) return false;
            a[c] = s1[i] - 'a';
            b[c++] = s2[i] - 'a';
        }
        return (c == 0) || (c == 2 && a[0] == b[1] && a[1] == b[0]);
    }
};
// @lc code=end

