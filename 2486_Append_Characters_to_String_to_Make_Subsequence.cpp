#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size(), m = t.size();
        int p = 0, q = 0;
        while (p < n && q < m) {
            if (s[p] == t[q]) {
                q++;
            }
            p++;
        }
        return m - q;
    }
};

signed main() {_
    Solution s;
    cout << s.appendCharacters("z", "abcde") << endl;

    return 0;
}
