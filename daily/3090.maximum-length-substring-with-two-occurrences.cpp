class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res = 0, l = 0;
        int c[26];
        auto a = [&](int x) { return s[x] - 'a'; };
        for(int r = 0;r < s.size();r++) {
            c[a(r)]++;
            while(c[a(r)] > 2) {
                c[a(l++)]--;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
