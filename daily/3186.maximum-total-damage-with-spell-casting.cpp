#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long maximumTotalDamage(vector<int>& power) {
            sort(power.begin(), power.end());
            vector<int> nums, cnt;
            for(auto x: power) {
                if(!nums.empty() && nums.back() == x) {
                    cnt.back()++;
                } else {
                    nums.push_back(x);
                    cnt.push_back(1);
                }
            }
            int N = nums.size();
            vector<long long> dp(N, 0);
            dp[0] = 1ll * nums[0] * cnt[0];
            for(int i = 1;i < N;i++) {
                int j = i - 1;
                while(j >= 0 && nums[i] - nums[j] <= 2) {
                    j--;
                }
                while(j >= 0 && j >= i - 5) {
                    dp[i] = max(dp[i], dp[j]);
                    j--;
                }
                dp[i] += 1ll * nums[i] * cnt[i];
            }
            long long ans = 0;
            for(int i = max(0, N - 3);i < N;i++) {
                ans = max(ans, dp[i]);
            }
            return ans;
        }
    };
