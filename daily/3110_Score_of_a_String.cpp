#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size();
        int ans = 0;
        char last = s[0];
        for(int i = 1;i < n;i++) {
            ans += abs(s[i] - last);
            last = s[i];
        }
        return ans;
    }
};

signed main() {_

    return 0;
}
