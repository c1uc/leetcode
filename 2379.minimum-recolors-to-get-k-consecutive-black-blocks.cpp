/*
 * @lc app=leetcode id=2379 lang=cpp
 *
 * [2379] Minimum Recolors to Get K Consecutive Black Blocks
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int c = 0;
        for (int i = 0; i < k; i++) {
            c += blocks[i] == 'W';
        }
        int ans = c;
        for (int i = k; i < blocks.size(); i++) {
            c += (blocks[i] == 'W') - (blocks[i - k] == 'W');
            ans = min(ans, c);
        }
        return ans;
    }
};
// @lc code=end

