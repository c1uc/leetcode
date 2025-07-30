#include <bits/stdc++.h>
#include <ranges>
using namespace std;


class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            int mx = ranges::max(nums);
            int ans = 0;
            ranges::fold_left(nums, 0, [&](int acc, int x) {
                if(x == mx) {
                    ans = max(ans, acc + 1);
                    return acc + 1;
                } else {
                    return 0;
                }
            });
            return ans;
        }
    };
