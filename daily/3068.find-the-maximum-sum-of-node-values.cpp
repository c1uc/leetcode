#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        bool c = 0;
        int mx = -INT_MAX, mn = INT_MAX;
        long long sum = 0;
        
        for (auto x: nums) {
            sum += x;
            int df = (x ^ k) - x;
            if(df > 0) {
                c ^= 1;
                sum += df;
                mn = min(mn, df);
            } else {
                mx = max(mx, df);
            }
        }
        if(c) return mx + mn > 0 ? sum + mx : sum - mn;
        return sum;
    }
};
