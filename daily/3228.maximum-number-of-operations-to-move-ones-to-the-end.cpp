#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int maxOperations(string s) {
            int ans = 0, cur = s[0] - '0', tot = s[0] - '0';
            for(int i = 1;i < s.size();i++) {
                if(s[i] == '0' && s[i - 1] == '1') ans += cur;
                else if(s[i] == '1' && s[i - 1] == '1') cur++, tot++;
                else if(s[i] == '1' && s[i - 1] == '0') cur = tot++ + 1;
            }
            return ans;
        }
    };