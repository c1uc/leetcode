/*
 * @lc app=leetcode id=2999 lang=cpp
 *
 * [2999] Count the Number of Powerful Integers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

auto log10(long long x) {
    return to_string(x).size();
}

class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        int n = log10(finish);

        reverse(s.begin(), s.end());

        auto count = [&](long long x) {
            vector<int> digits(n, 0);
            for(int i = 0; i < n; i++) {
                digits[i] = x % 10;
                x /= 10;
            }
            
            vector dp(n + 1, vector<long long>(2, 0));
            dp[n][0] = 0;
            dp[n][1] = 1;
            for(int i = n - 1; i >= 0; i--) {
                if(i < s.size()) {
                    dp[i][0] = (dp[i + 1][0] + dp[i + 1][1] * (s[i] - '0' < digits[i])) * (s[i] - '0' <= limit);
                    dp[i][1] = dp[i + 1][1] * (s[i] - '0' == digits[i] && s[i] - '0' <= limit);
                } else {
                    dp[i][0] = dp[i + 1][0] * (limit + 1) + dp[i + 1][1] * min(digits[i], limit + 1);
                    dp[i][1] = dp[i + 1][1] * (digits[i] <= limit);
                }
            }

            return dp[0][0] + dp[0][1];
        };

        return count(finish) - count(start - 1);
    }
};
// @lc code=end

