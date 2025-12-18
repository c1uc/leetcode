#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
            int n = prices.size();
            vector<long long> sum(n + 1, 0), strategy_sum(n + 1, 0);
            for(int i = 0;i < prices.size();i++) {
                sum[i + 1] = sum[i] + prices[i];
                strategy_sum[i + 1] = strategy[i] * prices[i] + strategy_sum[i];
            }
            long long ans = strategy_sum[n];
            for(int r_idx = k;r_idx <= n;r_idx++) {
                int l_idx = r_idx - k, mid_idx = (l_idx + r_idx) / 2;
                long long delta = (sum[r_idx] - sum[mid_idx]) - (strategy_sum[r_idx] - strategy_sum[l_idx]);
                ans = max(ans, delta + strategy_sum[n]);
            }
            return ans;
        }
    };
