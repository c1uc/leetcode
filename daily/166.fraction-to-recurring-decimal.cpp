#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    public:
        string fractionToDecimal(int numerator, int denominator) {
            if(numerator % denominator == 0) return to_string(numerator / denominator);
            long long num = numerator, den = denominator;
            bool neg = num < 0 ^ den < 0;
            num = abs(num), den = abs(den);
            string ans = to_string(num / den);
            num %= den;
            ans += ".";
            unordered_map<long long, int> mp;
            while(num) {
                if(mp.count(num)) {
                    ans.insert(mp[num], "(");
                    ans += ")";
                    break;
                }
                mp[num] = ans.size();
                num *= 10;
                ans += to_string(num / den);
                num %= den;
            }
            if(neg) ans = "-" + ans;
            return ans;
        }
    };
