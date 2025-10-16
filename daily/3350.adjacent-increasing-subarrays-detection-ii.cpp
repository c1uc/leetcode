#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int len = 1, prev_len = 0, ans = 0;
        for(int i = 1;i < n;++i) {
            if(nums[i] > nums[i - 1]) {
                len++;
            } else {
                ans = max(ans, max(len >> 1, min(prev_len, len)));
                prev_len = len;
                len = 1;
            }
        }
        ans = max(ans, max(len >> 1, min(prev_len, len)));
        return ans;
    }
};