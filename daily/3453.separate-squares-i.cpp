#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double lo = 1e9, hi = 0;
        for(const auto& sq: squares) {
            lo = min(lo, (double)sq[1]);
            hi = max(hi, (double)sq[1] + sq[2]);
        }
        while(lo + eps < hi) {
            double y = (lo + hi) / 2.0;
            double sum_u = 0.0, sum_d = 0.0;
            for(const auto& sq: squares) {
                double l = sq[2], h = sq[1];
                if(h >= y) {
                    sum_u += l * l;
                } else if(h + l <= y) {
                    sum_d += l * l;
                } else {
                    sum_u += l * (h + l - y);
                    sum_d += l * (y - h);
                }
            }
            if(sum_u <= sum_d) hi = y;
            else lo = y;
        }
        return lo;
    }
};