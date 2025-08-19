#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        long long distributeCandies(int n, int limit) {
            auto C2 = [&](long long x) {
                return x > 0 ? x * (x - 1) / 2 : 0;
            };
            return C2(n + 2) - 3ll * C2(n - (limit + 1) + 2) + 3ll * C2(n - 2 * (limit + 1) + 2) - C2(n - 3 * (limit + 1) + 2);
        }
    };
