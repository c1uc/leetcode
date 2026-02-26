class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        return nums | views::enumerate | views::transform( [&](auto v) { return nums[(((get<0>(v) + get<1>(v)) % n) + n) % n]; } ) | ranges::to<vector<int>>();
    }
};
