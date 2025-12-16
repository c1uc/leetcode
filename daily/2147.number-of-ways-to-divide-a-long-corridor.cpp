const int MOD = 1e9 + 7;

class Solution {
public:
    int numberOfWays(string corridor) {
        int spaces = 0, cnt = 0;
        long long ans = 1;
        for(auto x: corridor) {
            if(x == 'S') {
                if(cnt == 2) {
                    ans = ans * (1 + spaces) % MOD;
                    cnt = 1;
                    spaces = 0;
                } else {
                    cnt++;
                }
            } else {
                if(cnt == 2) spaces++;
            }
        }
        return cnt == 2 ? ans % MOD : 0;
    }
};