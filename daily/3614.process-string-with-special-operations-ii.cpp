class Solution {
public:
    char processStr(string s, long long k) {
        long long l = 0;
        for(const auto& c: s) {
            if(c == '*') l = (l > 0 ? l - 1 : 0);
            else if(c == '#') l <<= 1;
            else if(c == '%') continue;
            else ++l;
        }

        if(!l || k >= l) return '.';

        for(const auto& c: s | views::reverse) {
            if(c == '*') ++l;
            else if(c == '#') {
                l >>= 1;
                k %= l;
            } else if(c == '%') {
                k = l - k - 1;
            } else {
                if(k == l - 1) return c;
                --l;
            }
        }
        return '.';
    }
};
