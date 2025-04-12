/*
 * @lc app=leetcode id=3272 lang=cpp
 *
 * [3272] Find the Count of Good Integers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

vector<long long> factorial(11, 0);
auto init = []() {
    factorial[0] = 1;
    for(int i = 1; i <= 10; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
    return 0;
}();

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        set<vector<int>> freqMap;
        vector<int> digits(n, 0);
        vector<int> freq(10, 0);
        long long ans = 0;

        auto convert = [&](vector<int> &digits) -> long long {
            long long res = 0;
            for(int i = 0; i < digits.size(); i++) {
                res = res * 10 + digits[i];
            }
            return res;
        };

        auto count_permutation = [&](vector<int> &freq) -> long long {
            int len = accumulate(freq.begin(), freq.end(), 0);
            long long res = factorial[len];
            for(int i = 0; i < 10; i++) {
                res /= factorial[freq[i]];
            }
            return res;
        };

        auto dfs = [&](this auto &&dfs, int p, int q) -> void {
            if(p > q) {
                long long x = convert(digits);
                if(x % k == 0) {
                    if(freqMap.count(freq)) {
                        return;
                    }
                    freqMap.insert(freq);
                    ans += count_permutation(freq);
                    if(freq[0] > 0) {
                        freq[0]--;
                        ans -= count_permutation(freq);
                        freq[0]++;
                    }
                }
                return;
            }
            for(int j = 0; j < 10; j++) {
                if(p == 0 && j == 0) {
                    continue;
                }
                digits[p] = j;
                digits[q] = j;
                int pl = (p == q) ? 1 : 2;
                freq[j] += pl;
                dfs(p + 1, q - 1);
                freq[j] -= pl;
            }
        };
        dfs(0, n - 1);
        return ans;
    }
};
// @lc code=end

