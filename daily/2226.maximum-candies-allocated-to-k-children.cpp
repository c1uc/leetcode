/*
 * @lc app=leetcode id=2226 lang=cpp
 *
 * [2226] Maximum Candies Allocated to K Children
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        ll l = 1, r = *max_element(candies.begin(), candies.end()) + 1;

        auto valid = [&](int x){
            ll s = 0;
            for(auto i: candies) {
                s += i / x;
            }
            if(s >= k) return true;
            return false;
        };

        if(!valid(1)) return 0;

        while(l + 1 < r) {
            ll mid = (l + r) >> 1;
            if(valid(mid)) l = mid;
            else r = mid;
        }
        return l;
    }
};
// @lc code=end

