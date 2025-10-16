#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
    public:
        int countGoodStrings(int low, int high, int zero, int one) {
            vector<int> dp(high + 1, 0);
            dp[0] = 1;
            for(int i = 0;i <= high;i++) {
                if(i + zero <= high) {
                    dp[i + zero] = (dp[i + zero] + dp[i]) % MOD;
                }
                if(i + one <= high) {
                    dp[i + one] = (dp[i + one] + dp[i]) % MOD;
                }
            }
            return accumulate(dp.begin() + low, dp.end(), 0ll) % MOD;
        }
    };
