const long long MOD = 1e9 + 7;

class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        for(int i = 1;i <= n;i++) {
            int bits = 32 - __builtin_clz(i);
            ans = ((ans << bits) | i) % MOD;
        }
        return (int) ans;
    }
};
