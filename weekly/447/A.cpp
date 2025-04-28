#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> x_hi(n + 1, -1), x_lo(n + 1, 1e9), y_hi(n + 1, -1), y_lo(n + 1, 1e9);
        for(auto& b : buildings) {
            x_hi[b[0]] = max(x_hi[b[0]], b[1]);
            x_lo[b[0]] = min(x_lo[b[0]], b[1]);
            y_hi[b[1]] = max(y_hi[b[1]], b[0]);
            y_lo[b[1]] = min(y_lo[b[1]], b[0]);
        }

        int res = 0;

        for(int i = 0; i < buildings.size(); i++) {
            if(x_hi[buildings[i][0]] == -1) continue;
            if(x_lo[buildings[i][0]] == 1e9) continue;
            if(y_hi[buildings[i][1]] == -1) continue;
            if(y_lo[buildings[i][1]] == 1e9) continue;
            if(buildings[i][1] > x_lo[buildings[i][0]] && buildings[i][1] < x_hi[buildings[i][0]] && buildings[i][0] > y_lo[buildings[i][1]] && buildings[i][0] < y_hi[buildings[i][1]]) {
                res += 1;
            }
        }
        return res;
    }
};