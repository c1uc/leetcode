class Solution {
public:
    long long sumAndMultiply(int n) {
        long long mul = 1, sum = 0, rec = 0;
        while(n) {
            if(n % 10) {
                rec += mul * (n % 10);
                mul *= 10;
                sum += n % 10;
            }
            n /= 10;
        }
        return sum * rec;
    }
};
