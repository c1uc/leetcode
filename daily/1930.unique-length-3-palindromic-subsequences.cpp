#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int countPalindromicSubsequence(string s) {
            int n = s.size();
            int ans = 0;
            for (char c = 'a'; c <= 'z'; c++) {
                int first = -1, last = -1, mask = 0, new_mask;
                for (int i = 0; i < n; i++) {
                    if (s[i] == c) {
                        if (first == -1) first = i;
                        else {
                            new_mask = mask;
                            last = i;
                            mask |= (1 << (c - 'a'));
                        }
                    } else if(first != -1) mask |= (1 << (s[i] - 'a'));
                }
                if (first != -1 && last != -1) {
                    ans += __builtin_popcount((unsigned)new_mask);
                }
            }
            return ans;
        }
    };
