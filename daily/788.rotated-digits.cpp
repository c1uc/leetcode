int val[] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};

class Solution {
public:
    int rotatedDigits(int n) {
        auto chk = [&](int x) {
            int s = 0;
            while(x) {
                if(val[x % 10] == -1) return false;
                s += val[x % 10];
                x /= 10;
            }
            return (s > 0);
        };
        int res = 0;
        for(int i = 1;i <= n;i++) res += chk(i);
        return res;
    }
};
