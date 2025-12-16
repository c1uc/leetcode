#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long getDescentPeriods(vector<int>& prices) {
            long long ans = 0, l = 1;
            for(int i = 1;i < prices.size();i++) {
                if(prices[i] != prices[i - 1] - 1) {
                    ans += l * (l + 1) / 2;
                    l = 1;
                } else {
                    l++;
                }
            }
            return ans + (l * (l + 1) / 2);
        }
    };
