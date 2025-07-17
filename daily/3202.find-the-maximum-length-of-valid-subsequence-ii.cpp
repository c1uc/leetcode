#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int maximumLength(vector<int>& nums, int k) {
            vector<int> dp(k, 0);
            int ans = 0;
            for(int t = 0; t < k; ++t) {
                fill(dp.begin(), dp.end(), 0);
                for(auto x: nums) {
                    dp[t] = max(dp[t], dp[(t + k - (x % k)) % k] + 1);
                }
                ans = max(ans, dp[t]);
            }
            return ans;
        }
    };
