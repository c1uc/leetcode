#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 30;

vector<int> fact(MAXN + 1, 1);
vector<int> inv(MAXN + 1, 1);

auto modpow = [](int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = 1ll * res * a % MOD;
        a = 1ll * a * a % MOD;
        b >>= 1;
    }
    return res;
};

auto init = []() {
    for(int i = 2; i <= MAXN; i++) {
        fact[i] = 1ll * fact[i - 1] * i % MOD;
    }
    inv[MAXN] = modpow(fact[MAXN], MOD - 2);
    for(int i = MAXN - 1; i >= 0; i--) {
        inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    }
    return 0;
}();


class Solution {
    public:
        int magicalSum(int m, int k, vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> pows(n, vector<int>(m + 1, 0));
            for(int i = 0;i < n;i++) {
                pows[i][0] = 1;
                for(int j = 1;j <= m;j++) {
                    pows[i][j] = 1ll * pows[i][j - 1] * nums[i] % MOD;
                }
            }

            vector memo(n, vector(m + 1, vector(m + 1, vector<int>(k + 1, -1))));

            auto dp = [&](this auto&& dp, int i, int rem_cnt, int s, int rem_bits) -> int {
                int cnt = popcount((unsigned)s);
                if(cnt + rem_cnt < rem_bits) return 0;
                if(i == n || rem_cnt == 0 || rem_bits == 0) return rem_cnt == 0 && cnt == rem_bits;

                int& res = memo[i][rem_cnt][s][rem_bits];
                if(res != -1) return res;

                res = 0;
                for(int j = 0;j <= rem_cnt;j++) {
                    int r = dp(i + 1, rem_cnt - j, (s + j) >> 1, rem_bits - ((s + j) & 1));
                    res = (res + 1ll * r * pows[i][j] % MOD * inv[j] % MOD) % MOD;
                }
                return res;
            };

            return 1ll * dp(0, m, 0, k) * fact[m] % MOD;
        }
    };
