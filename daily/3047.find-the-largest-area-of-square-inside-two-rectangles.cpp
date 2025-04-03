/*
 * @lc app=leetcode id=3047 lang=cpp
 *
 * [3047] Find the Largest Area of Square Inside Two Rectangles
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();

        auto vmax = [](vector<int>& u, vector<int>& v) {
            return make_pair((long long)max(u[0], v[0]), (long long)max(u[1], v[1]));
        };
        auto vmin = [](vector<int>& u, vector<int>& v) {
            return make_pair((long long)min(u[0], v[0]), (long long)min(u[1], v[1]));
        };
        auto calc = [](pair<long long, long long>& u, pair<long long, long long>& v) {
            long long len = min(v.first - u.first, v.second - u.second);
            return len * len;
        };
        long long ans = 0;
        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n;j++) {
                auto u = vmax(bottomLeft[i], bottomLeft[j]);
                auto v = vmin(topRight[i], topRight[j]);
                if(u.first <= v.first && u.second <= v.second) {
                    ans = max(ans, calc(u, v));
                }
            }
        }
        return ans;
    }
};
// @lc code=end

