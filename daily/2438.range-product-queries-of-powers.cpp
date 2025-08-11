#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % MOD;
        a = 1ll * a * a % MOD;
        b >>= 1;
    }
    return res;
}


class Solution {
    public:
        vector<int> productQueries(int n, vector<vector<int>>& queries) {
            vector<int> prefix, powers;
            while(n) {
                int low_bit = n & -n;
                prefix.emplace_back(low_bit * (prefix.empty() ? 1 : prefix.back()) % MOD);
                powers.emplace_back(low_bit);
                n ^= low_bit;
            }
            vector<int> inv(prefix.size());
            inv.back() = qpow(prefix.back(), MOD - 2);
            for (int i = prefix.size() - 2; i >= 0; i--) {
                inv[i] = 1ll * inv[i + 1] * powers[i] % MOD;
            }
            vector<int> ans;
            for (auto& q : queries) {
                ans.emplace_back(1ll * prefix[q[1]] * (q[0] == 0 ? 1 : inv[q[0] - 1]) % MOD);
            }
            return ans;
        }
    };
