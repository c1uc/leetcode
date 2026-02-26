class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false;
        int x = 0, t = 0;
        vector<bool> chk(1 << k, false);
        for(int i = 0;i < k - 1;i++) x = (x << 1) | (s[i] - '0');
        for(int i = k - 1;i < s.size();i++) {
            x = (x << 1) | (s[i] - '0');
            x &= (1 << k) - 1;
            if(!chk[x]) t++;
            chk[x] = true;
        }
        return t == (1 << k);
    }
};
