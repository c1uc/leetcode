/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        
        auto is_vowel = [](char c) -> bool {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int ans = 0;
        for(int i = 0; i < k; i++) {
            ans += is_vowel(s[i]);
        }
        int max_ans = ans;
        for(int i = k; i < n; i++) {
            ans += is_vowel(s[i]) - is_vowel(s[i - k]);
            max_ans = max(max_ans, ans);
        }
        return max_ans;
    }
};
// @lc code=end

