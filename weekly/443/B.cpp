#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll INF = 1e18;

class Solution {
public:
    int longestPalindrome(string s, string t) {
        int n = s.size(), m = t.size();
        int ans = 1;

        auto is_palindrome = [](string& s) {
            int n = s.size();
            for(int i = 0; i < n / 2; i++) {
                if(s[i] != s[n - i - 1]) return false;
            }
            return true;
        };

        for(int l1 = 0; l1 < n; l1++) {
            for(int r1 = l1; r1 <= n; r1++) {
                for(int l2 = 0; l2 <= m; l2++) {
                    for(int r2 = l2; r2 <= m; r2++) {
                        string cat = s.substr(l1, r1 - l1) + t.substr(l2, r2 - l2);
                        if(is_palindrome(cat)) {
                            ans = max(ans, (r1 - l1) + (r2 - l2));
                        }
                    }
                }
            }
        }
        return ans;
    }
};