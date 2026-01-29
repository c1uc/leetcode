#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<int> minBitwiseArray(vector<int>& nums) {
            auto calc = [&](int x) -> int {
                if(!(x & 1)) return -1;
                int t = x + 1;
                return x ^ ((t & -t) >> 1);
            };
            for(int i = 0;i < nums.size();i++) nums[i] = calc(nums[i]);
            return nums;
        }
    };
