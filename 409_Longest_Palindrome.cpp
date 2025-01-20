//
// Created by duck on 2024/6/4.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        int ans = 0;
        for(auto c: mp) {
            ans += c.second / 2 * 2;
            if (ans % 2 == 0 && c.second % 2 == 1) {
                ans++;
            }
        }
        return ans;
    }
};

signed main() {_
    Solution s;
    cout << s.longestPalindrome("abccccdd") << endl;
    return 0;
}
