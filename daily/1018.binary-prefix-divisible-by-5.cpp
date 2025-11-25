#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<bool> prefixesDivBy5(vector<int>& nums) {
            int n = nums.size(), sum = 0;
            vector<bool> ans(n, false);
            for(int i = 0;i < n;i++) {
                sum = (sum << 1) | nums[i];
                ans[i] = (sum % 5) == 0;
                sum %= 5;
            }
            return ans;
        }
    };
