#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        string findLexSmallestString(string s, int a, int b) {
            set<string> vis;
            auto rotate = [&](string s) -> string {
                return s.substr(b) + s.substr(0, b);
            };
            auto add_a = [&](string s) -> string {
                for (int i = 1; i < s.size(); i += 2) {
                    s[i] = (s[i] - '0' + a) % 10 + '0';
                }
                return s;
            };

            auto dfs = [&](this auto&& dfs, string s) -> void {
                if (vis.count(s)) return;
                vis.insert(s);
                dfs(rotate(s));
                dfs(add_a(s));
            };
            dfs(s);
            return *vis.begin();
        }
    };
