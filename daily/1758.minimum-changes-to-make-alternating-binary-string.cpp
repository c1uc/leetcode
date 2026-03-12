class Solution {
public:
    int minOperations(string s) {
        int c = 0, n = s.size();
        for(int i = 0;i < n;i++) c += (i ^ (s[i] - '0')) & 1;
        return min(c, n - c);
    }
};
