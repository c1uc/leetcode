#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int maxFreqSum(string s) {
            auto isvowel = [](char v) {
                return (0x208222 >> (v & 0x1f)) & 1;
            };
            int freq[26] = {0};
            int ans = 0;
            for(int i = 0;i < s.size();i++) {
                if(isvowel(s[i])) {
                    freq[s[i] - 'a']++;
                } else {
                    freq[s[i] - 'a']--;
                }
            }
            return ranges::max(freq) - ranges::min(freq);
        }
    };
