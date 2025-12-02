#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
    public:
        int countTrapezoids(vector<vector<int>>& points) {
            unordered_map<int, int> cnt;
            for(auto &p : points) {
                cnt[p[1]]++;
            }
            int ans = 0, sum = 0;
            for(auto &[_, c] : cnt) {
                int s = (1ll * c * (c - 1)) / 2;
                ans += (1ll * sum * s) % MOD;
                sum += s;
                ans %= MOD;
                sum %= MOD;
            }
            return ans % MOD;
        }
    };