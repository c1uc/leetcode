/*
 * @lc app=leetcode id=1780 lang=cpp
 *
 * [1780] Check if Number is a Sum of Powers of Three
 */

// @lc code=start
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n > 1) {
            if(n % 3 == 2) {
                return false;
            }
            n /= 3;
        }
        return n == 1;
    }
};
// @lc code=end

