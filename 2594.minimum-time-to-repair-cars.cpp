/*
 * @lc app=leetcode id=2594 lang=cpp
 *
 * [2594] Minimum Time to Repair Cars
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mid ((l + r) >> 1)

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        auto valid = [&](ll x) {
            ll c = 0;
            for(auto i: ranks) {
                c += (long long)sqrt(x / i);
                if(c >= cars) return true;
            }
            return false;
        };

        ll l = 0, r = numeric_limits<ll>::max();
        while(l + 1 < r) {
            if(valid(mid)) r = mid;
            else l = mid;
        }
        return r;
    }
};
// @lc code=end

