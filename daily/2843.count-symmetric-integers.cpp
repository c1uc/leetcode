/*
 * @lc app=leetcode id=2843 lang=cpp
 *
 * [2843] Count Symmetric Integers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

vector<int> sym(10001, 0);
auto init = []() {
    vector<bool> is_sym(10001, false);
    for (int i = 1; i <= 10000; i++) {
        string s = to_string(i);
        if (s.length() % 2 == 0) {
            int n = s.length();
            int sum = 0;
            for (int j = 0; j < n / 2; j++) {
                sum += s[j] - '0';
            }
            for (int j = n / 2; j < n; j++) {
                sum -= s[j] - '0';
            }
            if (sum == 0) {
                is_sym[i] = true;
            }
        }
    }
    for (int i = 1; i <= 10000; i++) {
        if (is_sym[i]) {
            sym[i] = sym[i - 1] + 1;
        } else {
            sym[i] = sym[i - 1];
        }
    }
    return 1;
}();

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        return sym[high] - sym[low - 1];
    }
};
// @lc code=end

