#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minimumOneBitOperations(int n) {
            auto solve = [&](this auto&& solve, int n) -> int {
                if(n == 0) return 0;
                int b = bit_width((unsigned)n);
                return (1 << b) - 1 - solve(n - (1 << (b - 1)));
            };
            return solve(n);
        }
    };
