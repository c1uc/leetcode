class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = 0, n = s.size();
        for(;s[i] == '0' && i < n;i++);
        for(;s[i] == '1' && i < n;i++);
        for(;s[i] == '0' && i < n;i++);
        return i == s.size();
    }
};
