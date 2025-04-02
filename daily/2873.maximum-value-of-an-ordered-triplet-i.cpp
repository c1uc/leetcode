/*
 * @lc app=leetcode id=2873 lang=cpp
 *
 * [2873] Maximum Value of an Ordered Triplet I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int high = nums[0];
        long long ans = 0, diff = nums[0] - nums[1];
        for (int i = 1; i < n - 1; ++i) {
            if(nums[i - 1] > high) {
                high = nums[i - 1];
            }
            if(high - nums[i] > diff) {
                diff = high - nums[i];
            }
            ans = max(ans, diff * nums[i + 1]);
        }
        return ans;
    }
};
// @lc code=end