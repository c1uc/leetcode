#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minimumDifference(vector<int>& nums, int k) {
            ranges::sort(nums);
            int ans = INT_MAX;
            for(int i = 0;i + k - 1 < nums.size();i++) ans = min(ans, nums[i + k - 1] - nums[i]);
            return ans;
        }
    };
