#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int n = digits.size(), carry = 1;
            for(int idx = n - 1;idx >= 0 && carry;idx--) {
                carry = (digits[idx]++ == 9);
                digits[idx] %= 10;
            }
            if(carry) digits.insert(digits.begin(), 1);
            return digits;
        }
    };
