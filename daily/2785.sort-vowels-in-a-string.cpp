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
            vector<char*> v;
            vector<char> vc;
            for(auto &c: s | views::filter(isvowel)) {
                v.push_back(&c);
                vc.push_back(c);
            }
            ranges::sort(vc);
            for(int i = 0;i < v.size();i++) {
                *v[i] = vc[i];
            }
            return s;
        }
    };
