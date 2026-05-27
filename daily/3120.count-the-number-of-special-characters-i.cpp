static bool c[27][2];

class Solution {
public:
    int numberOfSpecialChars(string word) {
        memset(c, 0, sizeof(c));
        int ans = 0;
        for(const auto& x: word) {
            if(!c[x & 0b11111][(x >> 5) & 0b1] && c[x & 0b11111][(~x >> 5) & 0b1]) ans++;
            c[x & 0b11111][(x >> 5) & 0b1] = true;
        }
        return ans;
    }
};
