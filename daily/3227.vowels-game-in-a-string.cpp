#include <ranges>

class Solution {
public:
    bool doesAliceWin(string s) {
        return ranges::any_of(s, [](char c) {return (0x208222 >> (c & 0x1f)) & 1;} );
    }
};
