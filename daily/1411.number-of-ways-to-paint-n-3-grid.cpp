#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<long long>> matrix;
const int MOD = 1e9 + 7;

class Solution {
public:
    int numOfWays(int n) {
        auto mul = [&](matrix a, matrix b) -> matrix {
            int m = a.size(), t = a[0].size(), n = b[0].size();
            matrix res(m, vector<long long>(n, 0));
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < m;j++) {
                    for(int k = 0;k < t;k++) {
                        res[i][j] += a[i][k] * b[k][j];
                        res[i][j] %= MOD;
                    }
                }
            }
            return res;
        };

        auto fast_pow = [&](matrix mat, int x) -> matrix {
            matrix res = {{1, 0}, {0, 1}};
            while(x) {
                if(x & 1) {
                    res = mul(mat, res);
                }
                mat = mul(mat, mat);
                x >>= 1;
            }
            return res;
        };

        matrix m = {{3, 2}, {2, 2}};
        m = fast_pow(m, n - 1);
        return (m[0][0] + m[0][1] + m[1][0] + m[1][1]) * 6 % MOD;
    }
};
