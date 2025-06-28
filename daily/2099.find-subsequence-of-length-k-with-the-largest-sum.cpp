#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        auto v = nums | views::enumerate | ranges::to<vector<pair<int, int>>>();
        ranges::sort(v, [](auto a, auto b) {
            return get<1>(a) > get<1>(b);
        });
        auto v2 = v | views::take(k);
        ranges::sort(v2, [](auto a, auto b) {
            return get<0>(a) < get<0>(b);
        });
        return v2 | views::values | ranges::to<vector<int>>();
    }
};
