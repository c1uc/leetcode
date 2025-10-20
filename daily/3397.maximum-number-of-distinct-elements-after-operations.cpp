#include <bits/stdc++.h>
#include <ranges>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        ranges::sort(nums);
        int ans = 0, prev = -k;
        for(auto x: nums) {
            if(prev < x + k) {
                prev = max(prev + 1, x - k);
                ans++;
            }
        }
        return ans;
    }
};