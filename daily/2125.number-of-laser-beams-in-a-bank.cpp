#include <bits/stdc++.h>
#include <ranges>

using namespace std;

class Solution {
    public: int numberOfBeams(vector<string>& bank) {
        return ranges::fold_left(bank | views::transform([](const string& s) {
            return ranges::count(s, '1');
        }) | views::filter([](const int x) {
            return x > 0;
        }) | views::adjacent_transform <2> ([](const auto a, const auto b) {
            return a * b;
        }), 0, plus{});
    }
};