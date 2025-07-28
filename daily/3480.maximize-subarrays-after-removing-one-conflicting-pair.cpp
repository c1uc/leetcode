#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
            vector<vector<int>> g(n + 1);
            for(auto &x: conflictingPairs) {
                int a = x[0], b = x[1];
                if(a > b) swap(a, b);
                g[a].push_back(b);
            }
            
            ll ans = 0;
            vector<ll> dp(n + 2, 0);
            vector<int> mx = {n + 1, n + 1};
            for(int i = n;i > 0;i--) {
                mx.insert(mx.end(), g[i].begin(), g[i].end());
                sort(mx.begin(), mx.end());
                mx.resize(2);

                ans += mx[0] - i;
                dp[mx[0]] += mx[1] - mx[0];
            }
            return ans + *max_element(dp.begin(), dp.end());
        }
    };