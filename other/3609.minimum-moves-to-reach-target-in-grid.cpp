#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minMoves(int sx, int sy, int tx, int ty) {
            if(sx == tx && sy == ty) return 0;
            if(sx == 0 && sy == 0) return -1;
            int ans = 0;
            while(tx > sx || ty > sy) {
                if(tx > ty) {
                    if(tx >= 2 * ty) {
                        if(tx & 1) return -1;
                        tx >>= 1;
                    } else {
                        tx -= ty;
                    }
                } else if(ty > tx) {
                    if(ty >= 2 * tx) {
                        if(ty & 1) return -1;
                        ty >>= 1;
                    } else {
                        ty -= tx;
                    }
                } else {
                    if(sx == 0) tx = 0;
                    else if(sy == 0) ty = 0;
                    else return -1;
                }
                ans++;
            }
            if(tx != sx || ty != sy) return -1;
            return ans;
        }
    };
