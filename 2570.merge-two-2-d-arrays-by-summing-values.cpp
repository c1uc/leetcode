/*
 * @lc app=leetcode id=2570 lang=cpp
 *
 * [2570] Merge Two 2D Arrays by Summing Values
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i][0] == nums2[j][0]) {
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            } else if(nums1[i][0] < nums2[j][0]) {
                ans.push_back({nums1[i][0], nums1[i][1]});
                i++;
            } else {
                ans.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
        }
        while(i < nums1.size()) {
            ans.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }
        while(j < nums2.size()) {
            ans.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }
        return ans;
    }
};
// @lc code=end

