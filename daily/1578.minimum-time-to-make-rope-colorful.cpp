#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minCost(string colors, vector<int>& neededTime) {
            int ans = 0, prev = neededTime[0];
            for(int i = 1;i < colors.size();i++) {
                if(colors[i] == colors[i - 1]) {
                    ans += min(prev, neededTime[i]);
                    prev = max(prev, neededTime[i]);
                } else {
                    prev = neededTime[i];
                }
            }
            return ans;
            
        }
    };
