#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll INF = 1e18;

class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size(), low = 101;
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            low = min(low, cost[i]);
            ans[i] = low;
        }
        return ans;
    }
};
