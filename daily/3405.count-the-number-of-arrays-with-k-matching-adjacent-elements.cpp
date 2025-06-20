#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;
const int MAXN = 100000;

vector<int> fact(MAXN + 1, 1);
vector<int> inv(MAXN + 1, 1);

auto modpow(int a, int b, int mod)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

auto init = []()
{
    for (int i = 2; i <= MAXN; i++)
    {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
    }
    inv[MAXN] = modpow(fact[MAXN], MOD - 2, MOD);
    for (int i = MAXN - 1; i >= 1; i--)
    {
        inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;
    }
    return 0;
}();

class Solution
{
public:
    int countGoodArrays(int n, int m, int k)
    {
        return n == 1 ? m
                      : m *
                            (k == 0 ? 1
                                    : (1LL * fact[n - 1] * inv[k] % MOD *
                                       inv[n - k - 1] % MOD)) %
                            MOD * modpow(m - 1, n - k - 1, MOD) % MOD;
    }
};
