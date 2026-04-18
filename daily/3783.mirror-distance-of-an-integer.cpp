class Solution {
public:
    int mirrorDistance(int n) {
        return abs(n - [](int x) { int r = 0; while(x) { r = r * 10 + x % 10; x /= 10; } return r; }(n));
    }
};
