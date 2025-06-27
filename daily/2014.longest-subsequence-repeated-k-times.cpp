#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        auto chk = [&](string t) {
            int cnt = 0;
            for (int i = 0, j = 0; i < s.size(); ++i) {
                if (s[i] == t[j]) ++j;
                if (j == t.size()) ++cnt, j = 0;
            }
            return cnt >= k;
        };
        vector<int> cnt(26);
        for (char c : s) ++cnt[c - 'a'];
        string ans;
        queue<string> q;
        q.push("");
        while (!q.empty()) {
            string t = q.front();
            q.pop();
            for (auto c: t) cnt[c - 'a'] -= k;
            for(auto c: cnt | views::enumerate | ranges::views::filter([&](auto x) { return get<1>(x) >= k; }) | ranges::views::reverse | views::keys | views::transform([](auto x) { return char(x + 'a'); })) {
                string t2 = t + c;
                if (chk(t2)) {
                    q.push(t2);
                    ans = max(ans, t2, [](auto a, auto b) { return a.size() < b.size(); });
                }
            }
            for (auto c: t) cnt[c - 'a'] += k;
        }
        return ans;
    }
};
