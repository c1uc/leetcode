class Solution {
public:
    int smallestNumber(int n, int t) {
        auto chk = [&](int x) {
            int p = 1;
            while(x) {
                p *= x % 10;
                x /= 10;
            }
            return (p % t) == 0;
        };
        while(!chk(n)) n++;
        return n;
    }
};
