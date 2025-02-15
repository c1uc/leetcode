/*
 * @lc app=leetcode id=2698 lang=cpp
 *
 * [2698] Find the Punishment Number of an Integer
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int punishmentNumber(int n) {
        int l[] = {1, 9, 10, 36, 45, 55, 82, 91, 99, 100, 235, 297, 369, 370, 379, 414, 657, 675, 703, 756, 792, 909, 918, 945, 964, 990, 991, 999, 1000};
        int ans = 0;
        for(int i = 0;i < 29;i++) {
            if(l[i] <= n) ans += l[i] * l[i];
            else break;
        }
        return ans;
    }
};

int main() {
    auto check_valid = [&](int x) -> bool {
        for(int i = 0;;i++) {
            int k = x * x;
            int j = i, mul = 1, sum = 0;
            
            while(k) {
                if(j & 1) mul = 1;
                sum += k % 10 * mul;
                k /= 10;
                j >>= 1;
                mul *= 10;
            }
            if(sum == x) return true;
            if(i > 100) break;
        }
        return false;
    };
    for(int i = 1; i <= 1000; i++) {
        if(check_valid(i)) cout << i << ", ";
    }
    return 0;
}
// @lc code=end

