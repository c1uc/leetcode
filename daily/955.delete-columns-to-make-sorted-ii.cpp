#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minDeletionSize(vector<string>& strs) {
            int ans = 0;
            vector<string> v(strs.size());
            for(int i = 0;i < strs[0].size();i++) {
                bool flag = false;
                for(int j = 0;j < strs.size() - 1;j++) {
                    if(v[j] + strs[j][i] > v[j + 1] + strs[j + 1][i]) {
                        flag = true;
                        ans++;
                        break;
                    }
                }
                if(!flag) {
                    for(int j = 0;j < strs.size();j++) {
                        v[j] += strs[j][i];
                    }
                }
            }
            return ans;
        }
    };
