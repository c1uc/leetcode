#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int countCollisions(string directions) {
            int ans = 0, rc = 0, sc = 0;
            for(auto c : directions) {
                if(c == 'R') {
                    rc++;
                    sc = 0;
                } else if(c == 'L') {
                    if(rc) {
                        ans += rc + 1;
                        rc = 0;
                        sc = 1;
                    } else if(sc) {
                        ans += 1;
                    }
                } else {
                    ans += rc;
                    rc = 0;
                    sc = 1;
                }
            }
            return ans;
        }
    };
