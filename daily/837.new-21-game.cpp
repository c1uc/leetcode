#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        double new21Game(int n, int k, int maxPts) {
            if(k == 0) return 1.0;
            vector<double> dp(n + 1);
            dp[0] = 1;
            double sum = 1;
            for (int i = 1; i <= n; i++) {
                dp[i] = sum / maxPts;
                if (i < k) sum += dp[i];
                if (i - maxPts >= 0 && i - maxPts < k) sum -= dp[i - maxPts];
            }

            return accumulate(dp.begin() + k, dp.end(), 0.0);
        }
    };
