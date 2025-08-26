#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
            int max_area = 0, max_diag = 0;
            for(auto& d : dimensions) {
                int diag = d[0] * d[0] + d[1] * d[1];
                if(diag > max_diag) {
                    max_diag = diag;
                    max_area = d[0] * d[1];
                } else if(diag == max_diag && d[0] * d[1] > max_area) {
                    max_area = d[0] * d[1];
                }
            }
            return max_area;
        }
    };
