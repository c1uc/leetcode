#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<ll> cnt(26, 0);
        vector<vector<ll>> mat(26, vector<ll>(26, 0));
        for(auto c: s) cnt[c - 'a']++;
        for(int i = 0;i < 26;i++) {
            for(int j = 1;j <= nums[i];j++) mat[(i + j) % 26][i] = 1;
        }

        auto mulm = [&](vector<vector<ll>>& a, vector<vector<ll>>& b) {
            vector<vector<ll>> c(26, vector<ll>(26, 0));
            for(int i = 0;i < 26;i++) {
                for(int j = 0;j < 26;j++) {
                    for(int k = 0;k < 26;k++) {
                        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
                    }
                }
            }
            return c;
        };

        auto mulv = [&](vector<vector<ll>>& m, vector<ll>& v) {
            vector<ll> c(26, 0);
            for(int i = 0;i < 26;i++) {
                for(int j = 0;j < 26;j++) {
                    c[i] = (c[i] + m[i][j] * v[j]) % MOD;
                }
            }
            return c;
        };

        while(t) {
            if(t & 1) cnt = mulv(mat, cnt);
            mat = mulm(mat, mat);
            t >>= 1;
        }

        int ans = 0;
        for(int i = 0;i < 26;i++) ans = (ans + cnt[i]) % MOD;
        return ans;
    }
};
