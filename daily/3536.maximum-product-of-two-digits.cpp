class Solution {
public:
    int maxProduct(int n) {
        int a = 0, b = 0;
        while(n) {
            int c = n % 10;
            if(c >= a) b = a, a = c;
            else if(c > b) b = c;
            n /= 10;
        }
        return a * b;
    }
};
