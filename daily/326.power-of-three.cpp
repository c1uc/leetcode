#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


const int MAX_POWER = 0;

auto init = []() {
    for(int i = 0;;i++) {
        ll pwr = pow(3, static_cast<ll>(i));
        if(pwr > INT_MAX) break;
        MAX_POWER = pwr;
    }
    return 0;
}();

class Solution {
    public:
        bool isPowerOfThree(int n) {
            return n > 0 && MAX_POWER % n == 0;
        }
    };
