#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

class Solution {
public:
    int possibleStringCount(string word, int k) {
        vector<ll> items;
        ll c = 1, n = word.size(), ans = 1;

        if(n == k) return 1;
        if(n < k) return 0;

        for(int i = 0; i < n; i++) {
            if(i < n - 1 && word[i] == word[i + 1]) c++;
            else {
                if(c > 1) {
                    items.emplace_back(c - 1);
                    ans = (ans * c) % MOD;
                }
                c = 1;
                k--;
            }
        }

        if(k <= 0) return ans;
        int m = items.size();
        
        vector<ll> dp(k, 1);
        for(auto &cnt: items) {
            for(int i = 1; i < k; i++) {
                dp[i] = (dp[i] + dp[i - 1]) % MOD;
            }
            for(int j = k - 1; j > cnt; j--) {
                dp[j] = (dp[j] - dp[j - cnt - 1] + MOD) % MOD;
            }
        }
        return (ans - dp[k - 1] + MOD) % MOD;
    }
};
