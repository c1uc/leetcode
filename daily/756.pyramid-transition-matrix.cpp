#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        bool pyramidTransition(string bottom, vector<string>& allowed) {
            unordered_map<string, vector<string>> mp;
            for(auto &s : allowed) {
                mp[s.substr(0, 2)].push_back(s.substr(2));
            }
            auto dfs = [&](this auto&& dfs, string cur, string bottom) -> bool {
                if(cur.size() == 1 && bottom.size() == 2) return true;
                if(cur.size() == bottom.size() - 1) return dfs("", cur);

                for(auto &s : mp[bottom.substr(cur.size(), 2)]) {
                    if(dfs(cur + s, bottom)) return true;
                }
                return false;
            };
            return dfs("", bottom);
        }
    };
