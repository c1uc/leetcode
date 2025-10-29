class Solution {
    public:
        int smallestNumber(int n) {
            n |= n >> 1;
            n |= n >> 2;
            n |= n >> 4;
            n |= n >> 8;
            return (n | n >> 16);
        }
    };