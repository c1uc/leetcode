/*
 * @lc app=leetcode id=3169 lang=cpp
 *
 * [3169] Count Days Without Meetings
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int cur = 1, ans = 0;
        sort(meetings.begin(), meetings.end());
        for(auto& v: meetings) {
            if(v[0] > cur)
                ans += v[0] - cur;
            if(v[1] >= cur)
                cur = v[1] + 1;
        }
        return ans + (cur <= days ? days - cur + 1 : 0);
    }
};
// @lc code=end