#include <bits/stdc++.h>
using namespace std;

const int MOD = 10;
const int MAXN = 1e4 + 1;
int fact[MAXN];
int inv[MAXN];
int p2[MAXN];
int p5[MAXN];
int f2[] = {2, 4, 8, 6};

auto modpow = [](int a, int b, int mod) {
    int res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
};

auto init = []() {
    fact[0] = inv[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        int x = i;

        int e2 = countr_zero((unsigned)x);
        x >>= e2;

        int e5 = 0;
        while(x % 5 == 0) {
            e5++;
            x /= 5;
        }

        fact[i] = fact[i - 1] * x % MOD;
        inv[i] = modpow(fact[i], 3, MOD);

        p2[i] = p2[i - 1] + e2;
        p5[i] = p5[i - 1] + e5;
    }
    return 0;
}();

auto C = [](int n, int m) {
    int e2 = p2[n] - p2[m] - p2[n - m];
    int e5 = p5[n] - p5[m] - p5[n - m];
    return fact[n] * inv[m] * inv[n - m] * (e2 ? f2[(e2 - 1) % 4] : 1) * (e5 ? 5 : 1) % MOD;
};

class Solution {
    public:
        int triangularSum(vector<int>& nums) {
            int n = nums.size();
            int ans = 0;
            for(int i = 0;i < n;i++) {
                ans += C(n - 1, i) * nums[i] % MOD;
                ans %= MOD;
            }
            return ans;
        }
    };
