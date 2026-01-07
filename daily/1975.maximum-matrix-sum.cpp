#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long maxMatrixSum(vector<vector<int>>& matrix) {
            long long ans = 0;
            int mn = INT_MAX;
            bool f = 0;
            for(auto v: matrix) {
                for(auto x: v) {
                    ans += (x > 0 ? x : -x);
                    f ^= (x <= 0);
                    mn = min(max(x, -x), mn);
                }
            }
            return ans - (f ? 2 * mn : 0);
        }
    };
