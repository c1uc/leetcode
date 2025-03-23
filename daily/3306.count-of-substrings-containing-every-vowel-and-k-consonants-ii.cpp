/*
 * @lc app=leetcode id=3306 lang=cpp
 *
 * [3306] Count of Substrings Containing Every Vowel and K Consonants II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countOfSubstrings(string word, int k) {

        auto is_vowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        unordered_map<char, int> vowels = {{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
        int c_count = 0, extra = 0;
        int n = word.size();
        long long ans = 0;

        auto is_valid = [&]() {
            return vowels['a'] > 0 && vowels['e'] > 0 && vowels['i'] > 0 && vowels['o'] > 0 && vowels['u'] > 0 && c_count == k;
        };

        auto is_redundant = [&](char c) {
            return vowels[c] > 1 && vowels['a'] > 0 && vowels['e'] > 0 && vowels['i'] > 0 && vowels['o'] > 0 && vowels['u'] > 0 && c_count == k;
        };

        for(int l = 0, r = 0; r < n; r++) {
            if (!is_vowel(word[r])) {
                c_count++;
            }
            vowels[word[r]]++;

            while(c_count > k) {
                if (!is_vowel(word[l])) {
                    c_count--;
                }
                vowels[word[l]]--;
                l++;
                extra = 0;
            }

            while (l <= r && is_vowel(word[l]) && is_redundant(word[l])) {
                extra++;
                if (!is_vowel(word[l])) {
                    c_count--;
                }
                vowels[word[l]]--;
                l++;
            }

            if (is_valid()) {
                ans += extra + 1;
            }
        }

        return ans;
    }
};
// @lc code=end

