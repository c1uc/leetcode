#include <bits/stdc++.h>
#include <ranges>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        return ranges::any_of(complexity | views::drop(1), [&](int x) { return x <= complexity[0]; }) ? 0 : *ranges::fold_left_first(views::iota(1, (int)complexity.size()), [](int x, int y) { return 1ll * x * y % MOD; });
    }
};
