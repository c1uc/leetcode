#include <bits/stdc++.h>
#include <ranges>
using namespace std;


class Solution {
    public:
        int findSmallestInteger(vector<int>& nums, int value) {
            vector<int> freq(value, 0);
            for(auto x: nums) freq[(x % value + value) % value]++;
            auto it = ranges::min_element(freq);
            return value * *it + ranges::distance(freq.begin(), it);
        }
    };
