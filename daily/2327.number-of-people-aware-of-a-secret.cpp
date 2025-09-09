#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int peopleAwareOfSecret(int n, int delay, int forget) {
            const int MOD = 1e9 + 7;
            ll cur = 0, ans = 0;
            vector<int> spread(n + forget + 1, 0);
            spread[1] = 1;
            spread[2] = -1;
            for(int i = 1;i <= n;i++) {
                cur += spread[i];
                if(i + forget > n) {
                    ans = (ans + cur) % MOD;
                }
                spread[i + delay] = (spread[i + delay] + cur) % MOD;
                spread[i + forget] = (spread[i + forget] - cur + MOD) % MOD;
            }
            return ans;
        }
    };
