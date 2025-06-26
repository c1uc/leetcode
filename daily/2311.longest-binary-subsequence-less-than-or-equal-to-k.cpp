#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0, cur = 0;
        for (auto c : s | ranges::views::reverse) {
            if(ans >= 30) ans += c == '0';
            else {
                if(c == '0') ans++;
                else if(cur + (1 << ans) <= k) {
                    cur += 1 << ans;
                    ans++;
                }
            }
        }
        return ans;
    }
};
