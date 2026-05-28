static bool c[27][3];
static inline auto ex = [](auto x) -> int { return x & 0b11111; };
static inline auto cap = [](auto x) -> int { return (~x >> 5) & 1; };

class Solution {
public:
    int numberOfSpecialChars(string word) {
        memset(c, 0, sizeof(c));
        for(const auto& x: word) {
            if(cap(x) && !c[ex(x)][cap(x)] && c[ex(x)][cap(~x)]) c[ex(x)][2] = true;
            else if(!cap(x) && c[ex(x)][cap(~x)]) c[ex(x)][2] = false;
            c[ex(x)][cap(x)] = true;
        }
        return ranges::fold_left(views::iota(0, 27), 0, [&](int acc, int x) { return acc + c[x][2]; });
    }
};
