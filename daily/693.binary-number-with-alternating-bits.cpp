class Solution {
public:
    bool hasAlternatingBits(int n) {
        return __builtin_popcount(((unsigned)n + (n >> 1)) + 1) == 1;
    }
};
