class Solution {
    public:
        bool isPowerOfTwo(int n) {
            return n > 0 && popcount(static_cast<unsigned>(n)) == 1 ? true : false;
        }
    };