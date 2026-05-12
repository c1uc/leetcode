class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        return nums | views::transform( [](auto x) { vector<int> v; while(x) { v.emplace_back(x % 10); x /= 10; } reverse(v.begin(), v.end()); return v; } ) | views::join | ranges::to<vector<int>>();
    }
};
