#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int ans[MAXN];

auto f = []() {
    for(int i = 0;i < MAXN;i++) {
        ans[i] = -1;
        for(int j = 0;j < MAXN;j++) {
            if((j | (j + 1)) == i) {
                ans[i] = j;
                break;
            }
        }
    }
    return 'c';
}();


class Solution {
    public:
        vector<int> minBitwiseArray(vector<int>& nums) {
            for(int i = 0;i < nums.size();i++) {
                nums[i] = ans[nums[i]];
            }
            return nums;
        }
    };
