#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const int MAXN = 1e5;

vector<long long> dp(MAXN + 1, 0);
vector<long long> dp4(MAXN + 1, 0);

auto init = []() {
    dp[0] = 1;
    dp4[0] = 1;
    for(int i = 1;i <= MAXN;i++) {
        for(int j = 1;j <= 3;j++) {
            if(i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
        for(int j = 1;j <= 4;j++) {
            if(i - j >= 0) {
                dp4[i] = (dp4[i] + dp4[i - j]) % MOD;
            }
        }
    }

    return 0;
}();


class Solution {
    public:
        int countTexts(string pressedKeys) {
            int n = pressedKeys.size();
            long long ans = 1, len = 1;
            for(int i = 1;i < n;i++) {
                if(pressedKeys[i] == pressedKeys[i - 1]) {
                    len++;
                } else {
                    ans = (ans * (pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9' ? dp4[len] : dp[len])) % MOD;
                    len = 1;
                }
            }
            ans = (ans * (pressedKeys[n - 1] == '7' || pressedKeys[n - 1] == '9' ? dp4[len] : dp[len])) % MOD;
            return (int)ans;
        }
    };
