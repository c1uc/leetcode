#include <bits/stdc++.h>
#include <ranges>
using namespace std;

class Solution {
    public:
        int canBeTypedWords(string text, string brokenLetters) {
            int ans = 0;
            for(auto &s: text | views::split(' ')) {
                if(ranges::any_of(s, [&](char c) {return brokenLetters.find(c) != string::npos;})) {
                    continue;
                } else {
                    ans++;
                }
            }
            return ans;
        }
    };
