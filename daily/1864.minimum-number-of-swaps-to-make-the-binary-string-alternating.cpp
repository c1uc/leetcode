/*
 * @lc app=leetcode id=1864 lang=cpp
 *
 * [1864] Minimum Number of Swaps to Make the Binary String Alternating
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int c = 0, c0 = 0;
        for(int i = 0;i < n;++i) {
            if(i & 1 != s[i] - '0') {
                c++;
            }
            if(s[i] == '0') {
                c0++;
            } else {
                c0--;
            }
        }
        if(abs(c0) > 1) {
            return -1;
        }
        if(c0 == 0) {
            return min(c, n - c) >> 1;
        }
        if(c0 > 0) {
            return c;
        }
        return n - c;
    }
};
// @lc code=end

