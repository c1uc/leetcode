#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MOD = 1e9 + 7, MAXN = 1e4 + 1, LIM = 14;
vector<ll> F(MAXN + LIM, 1), INV_F(MAXN + LIM, 1);
vector<vector<int>> FACTOR(MAXN);

auto fast_pow = [](ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
};

auto init = []() {
    for (int i = 2; i < MAXN + LIM; ++i) F[i] = F[i - 1] * i % MOD;

    INV_F[MAXN + LIM - 1] = fast_pow(F[MAXN + LIM - 1], MOD - 2, MOD);
    for (int i = MAXN + LIM - 2; i >= 0; --i)
        INV_F[i] = INV_F[i + 1] * (i + 1) % MOD;

    for (int i = 2; i < MAXN; ++i) {
        int x = i;
        for (int p = 2; p * p <= x; ++p) {
            int cnt = 0;
            while (x % p == 0) {
                ++cnt;
                x /= p;
            }
            if (cnt) FACTOR[i].push_back(cnt);
        }
        if (x > 1) FACTOR[i].push_back(1);
    }
    return 1;
}();

class Solution
{
public:
    int idealArrays(int n, int maxValue)
    {
        auto C = [](int n, int m) {
            return m < 0 || m > n ? 0 : F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD;
        };

        ll ans = 0;

        for (int i = 1; i <= maxValue; ++i) {
            ll cnt = 1;
            for (auto c : FACTOR[i]) {
                cnt = cnt * C(n + c - 1, c) % MOD;
            }
            ans = (ans + cnt) % MOD;
        }

        return ans;
    }
};
