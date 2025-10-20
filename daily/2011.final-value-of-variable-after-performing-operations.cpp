#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int finalValueAfterOperations(vector<string>& operations) {
            int ans = 0;
            for(auto s: operations) {
                if(s[0] == '+' || s[2] == '+') ans++;
                else ans--;
            }
            return ans;
        }
    };
