#include <bits/stdc++.h>
#include <ranges>
using namespace std;


class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return ranges::count_if(nums, [&](int x) { return x % 3 != 0; });
    }
};