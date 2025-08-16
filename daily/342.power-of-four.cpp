#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        bool isPowerOfFour(int n) {
            return (n > 0) && (__builtin_popcount(n) == 1) && ((__builtin_ctz(n) & 1) == 0);
        }
    };
