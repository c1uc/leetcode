#include <bits/stdc++.h>
#include <ranges>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        return ranges::all_of(
            nums | 
            views::enumerate | 
            views::filter([&](auto p) { return get<1>(p) == 1; }) | 
            views::keys |
            views::pairwise | 
            views::transform([](auto p) { return get<1>(p) - get<0>(p); }),
            [&](auto dist) { return dist > k; }
        );
    }
};