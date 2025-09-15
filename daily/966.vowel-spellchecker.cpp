#include <bits/stdc++.h>
#include <ranges>
using namespace std;


class Solution {
    public:
        vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
            vector<string> ans;
            set<string> st;
            map<string, string> lower;
            map<string, string> vowel;

            auto isvowel = [](char c) {
                return (0x208222 >> (c & 0x1f)) & 1;
            };

            auto mask_vowel = [&](string s) {
                transform(s.begin(), s.end(), s.begin(), [&](char c) {
                    return isvowel(c) ? '-' : tolower(c);
                });
                return s;
            };

            auto to_lower = [](string s) {
                transform(s.begin(), s.end(), s.begin(), [&](char c) {
                    return tolower(c);
                });
                return s;
            };

            for(auto &word: wordlist | views::reverse) {
                st.insert(word);
                lower[to_lower(word)] = word;
                vowel[mask_vowel(word)] = word;
            }
            for(auto &query: queries) {
                if(st.count(query)) {
                    ans.push_back(query);
                } else if(lower.count(to_lower(query))) {
                    ans.push_back(lower[to_lower(query)]);
                } else if(vowel.count(mask_vowel(query))) {
                    ans.push_back(vowel[mask_vowel(query)]);
                } else {
                    ans.push_back("");
                }
            }
            return ans;
        }
    };
