/*
 * @lc app=leetcode id=1726 lang=cpp
 *
 * [1726] Tuple with Same Product
 */

// @lc code=start
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> m;
        for(int i = 0;i < nums.size();i++) {
            for(int j = i + 1;j < nums.size();j++) {
                int prod = nums[i] * nums[j];
                ans += m[prod];
                m[prod]++;
            }
        }
        return ans << 3;
    }
};
// @lc code=end

