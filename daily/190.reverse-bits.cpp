class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for(int _ = 0;_ < 32;_++) {
            res <<= 1;
            res |= (n & 1);
            n >>= 1;
        }
        return res;
    }
};
