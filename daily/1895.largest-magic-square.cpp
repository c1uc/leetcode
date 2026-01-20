#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int largestMagicSquare(vector<vector<int>>& g) {
            auto chk = [&](int x, int y, int l) -> bool {
                int tot = 0;
                for(int i = 0;i < l;i++) tot += g[x + i][y];
                for(int j = 0;j < l;j++) {
                    int s = 0;
                    for(int i = 0;i < l;i++) s += g[x + i][y + j];
                    if(s != tot) return false;
                }
                for(int i = 0;i < l;i++) {
                    int s = 0;
                    for(int j = 0;j < l;j++) s += g[x + i][y + j];
                    if(s != tot) return false;
                }
                int s1 = 0, s2 = 0;
                for(int i = 0;i < l;i++) {
                    s1 += g[x + i][y + i];
                    s2 += g[x + l - i - 1][y + i];
                }
                if(s1 != tot || s2 != tot) return false;
                return true;
            };
            int n = g.size(), m = g[0].size();
            for(int l = min(n, m);l > 0;l--) {
                for(int x = 0;x + l <= n;x++) {
                    for(int y = 0;y + l <= m;y++) {
                        if(chk(x, y, l)) return l;
                    }
                }
            }
            return 1;
        }
    };
