class Solution {
public:
    int bitwiseComplement(int n) {
        return n ^ (1 << (32 - __builtin_clz(max(n, 1)))) - 1;
    }
};
