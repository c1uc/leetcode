#include <bits/stdc++.h>
#include <ranges>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& v, int k) {
        long long ans = 0, t = 0;
        ranges::sort(v, greater<int>());
        for(auto x: v) {
            if(x <= t || t >= k) break;
            ans += x - (t++);
        }
        return ans;
    }
};