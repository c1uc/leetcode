#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int rem = mean * (m + n) - sum;
        if(rem < n || rem > 6 * n) return {};
        vector res = vector<int>(n, rem / n);
        for(int i = 0;i < rem % n;i++) {
            res[i]++;
        }
        return res;
    }
};


signed main() {_

    return 0;
}
