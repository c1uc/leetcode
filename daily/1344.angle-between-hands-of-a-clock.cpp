class Solution {
public:
    double angleClock(int h, int m) {
        return [&, d = 30.0 * (h % 12) - 5.5 * m] { return min(abs(d), 360.0 - abs(d)); }();
    }
};
