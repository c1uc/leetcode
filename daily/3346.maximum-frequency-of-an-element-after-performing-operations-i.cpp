#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int maxFrequency(vector<int>& nums, int k, int numOperations) {
            int mx = *max_element(nums.begin(), nums.end());
            map<int, int> count, df;
            for(auto x: nums) {
                count[x]++;
                df[x]++;
                df[x]--;
                df[max(0, x - k)]++;
                df[x + k + 1]--;
            }
            int ans = 0, sum_df = 0;
            for(auto [x, y]: df) {
                sum_df += y;
                ans = max(ans, count[x] + min(sum_df - count[x], numOperations));
            }
            return ans;
        }
    };
