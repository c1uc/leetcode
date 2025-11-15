#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int numberOfSubstrings(string s) {
            int ans = 0, num1 = 0;
            vector<int> pos0 = {-1};
            for(int r = 0;r < s.size();r++) {
                if(s[r] == '0') pos0.push_back(r);
                else {
                    num1++;
                    ans += r - pos0.back();
                }
                int m = pos0.size();
                for(int i = m - 1;i > 0 && (m - i) * (m - i) <= num1;i--) {
                    int p = pos0[i - 1], q = pos0[i];
                    int cnt0 = m - i;
                    int cnt1 = r - q + 1 - cnt0;
                    ans += max(0, q - max(0, cnt0 * cnt0 - cnt1) - p);
                }
            }
            return ans;
        }
    };
