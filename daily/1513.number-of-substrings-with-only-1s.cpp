#include <bits/stdc++.h>
#include <ranges>
using namespace std;

const int MOD = 1e9 + 7;


class Solution {
    public:
        int numSub(string s) {
            return ranges::fold_left(views::chunk_by(s, [](auto a, auto b) { return a == '1' && b == '1'; }) | views::filter([](auto x) { return ranges::any_of(x, [](auto y) { return y == '1'; }); }) | views::transform([](auto x) { return ranges::size(x); }) | ranges::to<vector<int>>(), 0, [](auto acc, auto x) { return (acc + (long long)x * (x + 1) / 2) % MOD; });
        }
    };