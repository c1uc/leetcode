/*
 * @lc app=leetcode id=2342 lang=cpp
 *
 * [2342] Max Sum of a Pair With Equal Sum of Digits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<pii> res(82, pii(-1, -1));

        auto getSum = [&](int n) {
            int sum = 0;
            while(n) {
                sum += n % 10;
                n /= 10;
            }
            return sum;
        };

        for(int n: nums) {
            int sum = getSum(n);
            if(res[sum].first < n) {
                res[sum].second = res[sum].first;
                res[sum].first = n;
            } else if(res[sum].second < n) {
                res[sum].second = n;
            }
        }

        int ans = -1;
        for(int i = 1; i < 81; i++) {
            if(res[i].first != -1 && res[i].second != -1) {
                ans = max(ans, get<0>(res[i]) + get<1>(res[i]));
            }
        }
        return ans;
    }
};
// @lc code=end

