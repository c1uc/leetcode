#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minPairSum(vector<int>& nums) {
            ranges::sort(nums);
            int mx = 0, n = nums.size();
            for(int i = 0;i < n / 2;i++) mx = max(nums[i] + nums[n - i - 1], mx);
            return mx;
        }
    };
