#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
            int h = 2, v = 2, c = 2;
            ranges::sort(hBars);
            ranges::sort(vBars);
            for(int i = 0;i < hBars.size() - 1;i++) {
                if(hBars[i] == hBars[i + 1] - 1) c++;
                else c = 2;
                h = max(h, c);
            }
            c = 2;
            for(int i = 0;i < vBars.size() - 1;i++) {
                if(vBars[i] == vBars[i + 1] - 1) c++;
                else c = 2;
                v = max(v, c);
            }
            return min(h * h, v * v);
        }
    };
