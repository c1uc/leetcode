#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;

class Solution {
public:
    int colorTheGrid(int m, int n) {
        vector<int> valid;
        for(int i = 0;i < (int)(pow(3, m));i++) {
            int prev = -1;
            int cur = i;
            bool flag = true;
            for(int j = 0;j < m;j++) {
                int t = cur % 3;
                cur /= 3;
                if(t == prev) {
                    flag = false;
                    break;
                }
                prev = t;
            }
            if(flag) valid.push_back(i);
        }

        auto check = [&](int a, int b) {
            for(int i = 0;i < m;i++) {
                if(a % 3 == b % 3) return false;
                a /= 3;
                b /= 3;
            }
            return true;
        };
        
        vector<unordered_set<int>> mp(valid.size());
        for(int i = 0;i < valid.size();i++) {
            for(int j = i + 1;j < valid.size();j++) {
                if(check(valid[i], valid[j])) {
                    mp[i].insert(j);
                    mp[j].insert(i);
                }
            }
        }

        vector<int> dp(valid.size(), 0);
        for(int i = 0;i < valid.size();i++) {
            dp[i] = 1;
        }

        for(int i = 1;i < n;i++) {
            vector<int> dp2(valid.size(), 0);
            for(int j = 0;j < valid.size();j++) {
                for(auto k : mp[j]) {
                    dp2[j] += dp[k];
                    dp2[j] %= MOD;
                }
            }
            dp = dp2;
        }
        
        int ans = 0;
        for(int i = 0;i < valid.size();i++) {
            ans += dp[i];
            ans %= MOD;
        }
        return ans;
    }
};
