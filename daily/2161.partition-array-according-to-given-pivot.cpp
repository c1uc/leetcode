/*
 * @lc app=leetcode id=2161 lang=cpp
 *
 * [2161] Partition Array According to Given Pivot
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        
        int l[100001], r[100001];
        int lcnt = 0, rcnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                l[lcnt++] = nums[i];
            } else if(nums[i] > pivot) {
                r[rcnt++] = nums[i];
            }
        }

        for (int i = 0; i < lcnt; i++) {
            nums[i] = l[i];
        }

        for(int i = 0; i < n - lcnt - rcnt; i++) {
            nums[lcnt + i] = pivot;
        }

        for (int i = 0; i < rcnt; i++) {
            nums[n - rcnt + i] = r[i];
        }

        return nums;
    }
};
// @lc code=end

