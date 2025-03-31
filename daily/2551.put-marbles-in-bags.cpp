/*
 * @lc app=leetcode id=2551 lang=cpp
 *
 * [2551] Put Marbles in Bags
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k == 1 || k == weights.size()) return 0;

        int n = weights.size();
        vector<int> sum(n - 1);
        for(int i = 0;i < n - 1;i++) {
            sum[i] = weights[i] + weights[i + 1];
        }

        if(k > (n >> 1)) k = n - k + 1;
        
        long long ans = 0;
        nth_element(sum.begin(), sum.begin() + k - 1, sum.end());
        ans -= reduce(sum.begin(), sum.begin() + k - 1);

        nth_element(sum.begin(), sum.end() - k + 1, sum.end());
        ans += reduce(sum.end() - k + 1, sum.end());

        return ans;
    }
};
// @lc code=end

