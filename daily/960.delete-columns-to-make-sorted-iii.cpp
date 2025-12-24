#include <bits/stdc++.h>
#include <ranges>
using namespace std;


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<int> dp(m, 1);
        for(int j = 1;j < m;j++) {
            for(int i = 0;i < j;i++) {
                bool flag = true;
                for(int k = 0;k < n;k++) {
                    if(strs[k][j] < strs[k][i]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        return m - ranges::max(dp);
    }
};
