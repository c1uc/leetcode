#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
    public:
        long long maxSubarraySum(vector<int>& nums, int k) {
            vector<ll> prefix(nums.size() + 1, 0);
            for(int i = 1; i <= nums.size(); i++) {
                prefix[i] = prefix[i - 1] + nums[i - 1];
            }

            ll ans = prefix[k];

            for(int i = 0; i < k;i++) {
                ll sum = 0;
                for(int j = i + k;j < prefix.size();j += k) {
                    sum += prefix[j] - prefix[j - k];
                    ans = max(ans, sum);
                    sum = max(sum, 0LL);
                }
            }
            return ans;
        }
    };
