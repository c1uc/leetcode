#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int totalMoney(int n) {
            return 28 * (n / 7) + ((n / 7 - 1) * 7) * (n / 7) / 2 + ((1 + n / 7) + (n / 7 + n % 7)) * (n % 7) / 2;
        }
    };
