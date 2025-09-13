#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        string sortVowels(string s) {
            auto isvowel = [](char v) {
                return (0x208222 >> (v & 0x1f)) & 1;
            };
            auto vc = s | views::filter(isvowel) | ranges::to<vector<char>>();
            ranges::sort(vc);
            return s | views::transform([&, i = 0](char c) mutable {return isvowel(c) ? vc[i++] : c;}) | ranges::to<string>();
        }
    };
