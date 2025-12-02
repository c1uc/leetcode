#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long maxRunTime(int n, vector<int>& batteries) {
            long long s = accumulate(batteries.begin(), batteries.end(), 0LL), n = batteries.size();
            sort(batteries.begin(), batteries.end(), greater<int>());
            for(auto x: batteries) {
                if(x <= s / n) return s / n;
                s -= x;
                n--;
            }
            return s / n;
        }
    };
