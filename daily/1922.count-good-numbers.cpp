#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MOD = 1e9 + 7;

class Solution {
public:
    int countGoodNumbers(long long n) {
        auto modpow = [](long long a, long long b, long long mod) {
            long long res = 1;
            while (b > 0) {
                if (b & 1) res = res * a % mod;
                a = a * a % mod;
                b >>= 1;
            }
            return res;
        };

        return modpow(4, n >> 1, MOD) * modpow(5, n - (n >> 1), MOD) % MOD;
    }
};