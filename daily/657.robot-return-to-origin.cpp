class Solution {
public:
    bool judgeCircle(string moves) {
        return ranges::fold_left(moves, pair{0,0}, [](auto p, char c) {
            return pair{p.first + (c == 'R') - (c == 'L'), p.second + (c == 'U') - (c == 'D')};
        }) == pair{0,0};
}
};
