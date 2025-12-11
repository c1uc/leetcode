#include <bits/stdc++.h>
#include <ranges>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        return ranges::fold_left(nums | views::transform( [](int x) { return x & 1; } ), 0, plus<int>()) & 1 ? 0 : nums.size() - 1;
    }
};
