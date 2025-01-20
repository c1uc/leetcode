#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

class Solution {
public:
    int minimumLength(string s) {
        int freq[26] = {};
        for(char c : s) freq[c - 'a']++;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += freq[i] > 2 ? (freq[i] - 1) % 2 + 1 : freq[i];
        }
        return ans;
    }
};


signed main() {_

    return 0;
}
