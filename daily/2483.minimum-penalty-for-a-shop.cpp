#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + (customers[i - 1] == 'Y' ? 1 : 0);
        }
        int ans = 0;
        for(int i = 0; i <= n; i++) {
            int cur = (i - prefix[i]) + (prefix[n] - prefix[i]);
            if(cur < (ans - prefix[ans]) + (prefix[n] - prefix[ans])) {
                ans = i;
            }
        }
        return ans;
    }
};