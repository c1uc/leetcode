/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double max_avg = (double)sum / k;
        for(int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            max_avg = max(max_avg, (double)sum / k);
        }
        return max_avg;
    }
};
// @lc code=end

