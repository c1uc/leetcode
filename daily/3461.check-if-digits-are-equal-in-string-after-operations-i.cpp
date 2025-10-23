#include <bits/stdc++.h>
using namespace std;

const int MOD = 10;

int fact[101][101];
auto init = []() {
    fact[0][0] = 1;
    for(int i = 1; i <= 100; i++) {
        fact[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            fact[i][j] = fact[i - 1][j - 1] + fact[i - 1][j];
            fact[i][j] %= MOD;
        }
    }
    return 0;
}();

auto conv = [](string s) -> int {
    int res = 0, n = s.size();
    for(int i = 0; i < n; i++) {
        res += fact[n - 1][i] * (s[i] - '0') % MOD;
        res %= MOD;
    }
    return res;
};

class Solution {
    public:
        bool hasSameDigits(string s) {
            return conv(s.substr(0, s.size() - 1)) == conv(s.substr(1, s.size() - 1));
        }
    };
