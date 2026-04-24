class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        return [](int x) { return abs(x % 10000 - 50) + x / 10000; }(ranges::fold_left(moves, 50, [](int x, auto m) { return x + 10000 * (m == '_') + 1 * (m == 'L') - 1 * (m == 'R'); }) );
    }
};
