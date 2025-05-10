#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll MOD = 1e9 + 7;

vi fact(81);
vi inv(81);

auto modpow = [](ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
};

auto init = []() {
    fact[0] = 1;
    for (int i = 1; i <= 80; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv[80] = modpow(fact[80], MOD - 2, MOD);
    for (int i = 79; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
    return 'c';
}();


class Solution {
public:
    int countBalancedPermutations(string num) {
        int n = num.size();
        int ans = 0;
        
        vi freq(10, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            freq[num[i] - '0']++;
            sum += num[i] - '0';
        }
        if (sum & 1) return 0;
        int half = sum >> 1;

        int odd = (n + 1) >> 1;
        vector dp(11, vector(half + 1, vector<ll>(odd + 1, -1)));
        dp[10][0][0] = 1;

        auto dfs = [&](auto &&dfs, int idx, int sum, int odd) {
            if (dp[idx][sum][odd] != -1) return dp[idx][sum][odd];
            if (idx == 10) {
                return dp[idx][sum][odd] = (odd == 0) && (sum == 0);
            }
            ll res = 0;
            for (int x = 0; x <= freq[idx]; x++) {
                if (x * idx > sum || x > odd) break;
                res += (dfs(dfs, idx + 1, sum - x * idx, odd - x) * inv[x] % MOD) * inv[freq[idx] - x] % MOD;
            }
            return dp[idx][sum][odd] = res % MOD;
        };
        return dfs(dfs, 0, half, odd) * fact[odd] % MOD * fact[n - odd] % MOD;
    }
};
