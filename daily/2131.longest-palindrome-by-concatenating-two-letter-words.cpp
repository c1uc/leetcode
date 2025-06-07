#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_multiset<string> st;
        for(auto &word : words) {
            if(st.count(word)) {
                ans += 4;
                st.erase(st.find(word));
            } else {
                string rev = word;
                reverse(rev.begin(), rev.end());
                st.insert(rev);
            }
        }
        for(auto &word : st) {
            if(word[0] == word[1]) {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};