/*
 * @lc app=leetcode id=3396 lang=cpp
 *
 * [3396] Minimum Number of Operations to Make Elements in Array Distinct
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        int idx = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s.count(nums[i])) {
                idx = i + 1;
                break;
            }
            s.insert(nums[i]);
        }
        return 3 * (idx / 3 + (idx % 3 ? 1 : 0));
    }
};
// @lc code=end

