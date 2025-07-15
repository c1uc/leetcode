#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        bool isValid(string word) {
            auto isVowel = [](char c) {
                c = tolower(c);
                return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
            };
            int vowel = ranges::count_if(word, isVowel);
            int consonant = ranges::count_if(word, [&](char c) {
                return isalpha(c) && !isVowel(c);
            });
            int illegal = ranges::count_if(word, [&](char c) {
                return !isalpha(c) && !isdigit(c);
            });
            return word.size() >= 3 && vowel && consonant && !illegal;
        }
    };