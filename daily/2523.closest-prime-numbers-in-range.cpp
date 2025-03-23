/*
 * @lc app=leetcode id=2523 lang=cpp
 *
 * [2523] Closest Prime Numbers in Range
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> nums(1000001, 1);
        vector<int> Primes;

        for(int i = 2; i <= 1000000; i++) {
            if(nums[i] == 1) {
                Primes.emplace_back(i);
                for(int j = 2 * i; j <= 1000000; j += i) {
                    nums[j] = 0;
                }
            }
        }

        int minDiff = INT_MAX;
        vector<int> res(2);

        int l = lower_bound(Primes.begin(), Primes.end(), left) - Primes.begin();
        int r = upper_bound(Primes.begin(), Primes.end(), right) - Primes.begin();

        if(r - l < 2) return {-1, -1};
        for(int i = l; i + 1 < r; i++) {
            if(Primes[i + 1] - Primes[i] < minDiff) {
                minDiff = Primes[i + 1] - Primes[i];
                res[0] = Primes[i];
                res[1] = Primes[i + 1];
            }
        }
        return res;
    }
};
// @lc code=end

