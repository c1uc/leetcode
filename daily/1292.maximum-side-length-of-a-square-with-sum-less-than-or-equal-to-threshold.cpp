#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int maxSideLength(vector<vector<int>>& pref, int t) {
            const int n = pref.size(), m = pref[0].size();
            for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) {
                if(!i && !j) continue;
                pref[i][j] += (i ? pref[i - 1][j] : 0) + (j ? pref[i][j - 1] : 0) - (i && j ? pref[i - 1][j - 1] : 0);
            }
    
            const auto chk = [&](int l) -> bool {
                for(int x = 0;x + l <= n;x++) for(int y = 0;y + l <= m;y++) {
                    if(pref[x + l - 1][y + l - 1] - (y ? pref[x + l - 1][y - 1] : 0) - (x ? pref[x - 1][y + l - 1] : 0) + (x && y ? pref[x - 1][y - 1] : 0) <= t) return true;
                }
                return false;
            };
    
            int l = 0, r = min(n, m) + 1;
            while(l + 1 < r) {
                int mid = (l + r) >> 1;
                if(chk(mid)) l = mid;
                else r = mid;
            }
            return l;
        }
    };
