#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<string> removeAnagrams(vector<string>& words) {
            string prev = "";
            int i = 0;
            while(i < words.size()) {
                auto cur = words[i];
                sort(cur.begin(), cur.end());
                if(cur == prev) {
                    words.erase(words.begin() + i);
                } else {
                    prev = cur;
                    i++;
                }
            }
            return words;
        }
    };
