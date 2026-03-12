class Solution {
public:
    int minFlips(string s) {
        if(s.size() == 1) return 0;
        int ans = 1e5 + 1, n = s.size(), c = 0;
        for(int i = 0;i < 2 * n - 1;i++) {
            if(i >= n) {
                ans = min({c, n - c, ans});
                c -= ((i - n) ^ s[i - n]) & 1;
            }
            c += (i ^ s[i % n]) & 1;
        }
        return min({ans, c, n - c});
    }
};
