class Solution {
public:
    int binaryGap(int n) {
        while(!(n & 1)) n >>= 1;
        if(n == 1) return 0;
        int ans = 0, cur = 0;
        while(n) {
            while(n && !(n & 1)) {
                cur++;
                n >>= 1;
            }
            ans = max(ans, cur);
            cur = 0;
            while(n & 1) n >>= 1;
        }
        return ans + 1;
    }
};
