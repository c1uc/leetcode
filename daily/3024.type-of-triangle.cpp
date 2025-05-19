#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    string triangleType(vector<int>& nums) {
        int hi = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(hi >= sum - hi) return "none";
        if(hi == nums[0] && hi == nums[1] && hi == nums[2]) return "equilateral";
        if(nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) return "isosceles";
        return "scalene";
    }
};
