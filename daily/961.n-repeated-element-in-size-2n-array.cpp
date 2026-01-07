#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int repeatedNTimes(vector<int>& nums) {
            int c[10001] = {0};
            for(auto x: nums) {
                if(c[x]++) return x;
            }
            return -1;
        }
    };
