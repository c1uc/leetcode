/*
 * @lc app=leetcode id=3356 lang=cpp
 *
 * [3356] Zero Array Transformation II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int l = 0, r = queries.size();

        vector<int> diff(n + 1);
        auto valid = [&](int x) {
            fill(diff.begin(), diff.end(), 0);
            for(int i = 0;i < x;i++) {
                diff[queries[i][0]] -= queries[i][2];
                diff[queries[i][1] + 1] += queries[i][2];
            }

            int sum = 0;
            for(int i = 0; i < n; i++) {
                sum += diff[i];
                if(nums[i] + sum > 0) return false;
            }
            return true;
        };

        if(valid(0)) return 0;
        if(!valid(queries.size())) return -1;

        while(l + 1 < r) {
            int mid = (l + r) >> 1;
            if(!valid(mid)) l = mid;
            else r = mid;
        }
        return r;
    }
};
// @lc code=end

