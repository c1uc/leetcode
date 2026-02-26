vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        auto test = [&](int x) -> bool {
            for(auto p: primes) {
                if(p == x) return true;
            }
            return false;
        };
        for(unsigned i = left;i <= right;i++) {
            int b = __builtin_popcount(i);
            ans += test(b);
        }
        return ans;
    }
};
