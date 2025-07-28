#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int maximumGain(string s, int x, int y) {
            int ans = 0;
            
            int a = 0, b = 0;

            for(auto c: s) {
                if(c > 'b') {
                    ans += min(a, b) * min(x, y);
                    a = 0;
                    b = 0;
                } else if(c == 'a') {
                    if(y > x && b > 0) {
                        ans += y;
                        b--;
                    } else {
                        a++;
                    }
                } else if(c == 'b') {
                    if(x > y && a > 0) {
                        ans += x;
                        a--;
                    } else {
                        b++;
                    }
                }
            }
            ans += min(a, b) * min(x, y);
            return ans;
        }
    };