#include <bits/stdc++.h>
#include <ranges>
using namespace std;


class Solution {
    public:
        bool hasIncreasingSubarrays(vector<int>& nums, int k) {
            if(k == 1) return nums.size() > 1;
            int len = 1, prev_len = 0;
            for(auto x: nums | views::pairwise_transform([](auto a, auto b) {
                return b > a;
            })) {
                if(x) {
                    len++;
                    if(len >= k && prev_len >= k || len >= (k << 1)) {
                        return true;
                    }
                } else {
                    prev_len = len;
                    len = 1;
                }
            }
            return false;
        }
    };
