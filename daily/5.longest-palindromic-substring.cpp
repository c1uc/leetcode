#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0;
        string ans;
        for(int i = 0; i < s.size(); i++) {
            for(int l = 0; l < s.size(); l++) {
                if(i - l < 0 || i + l >= s.size() || s[i - l] != s[i + l]) break;
                if(2 * l + 1 > max_len) {
                    max_len = 2 * l + 1;
                    ans = s.substr(i - l, 2 * l + 1);
                }
            }
            for(int l = 0; l < s.size(); l++) {
                if(i - l < 0 || i + l + 1 >= s.size() || s[i - l] != s[i + l + 1]) break;
                if(2 * l + 2 > max_len) {
                    max_len = 2 * l + 2;
                    ans = s.substr(i - l, 2 * l + 2);
                }
            }
        }
        return ans;
    }
};