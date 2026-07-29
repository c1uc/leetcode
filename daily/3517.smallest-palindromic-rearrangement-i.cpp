class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int half = n & 1 ? n >> 1 : n >> 1;
        sort(s.begin(), s.begin() + half);
        for(int i = 0; i < half; i++) {
            s[i] = s[i];
        }
        for(int i = half; i < n; i++) {
            s[i] = s[n - i - 1];
        }
        return s;
    }
};
