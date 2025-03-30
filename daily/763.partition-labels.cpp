/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> last(26, -1);
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {    
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                ans.emplace_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;

    }
};
// @lc code=end

