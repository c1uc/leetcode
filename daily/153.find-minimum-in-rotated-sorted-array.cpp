class Solution {
public:
    int findMin(vector<int>& nums) {
        return [&, it = lower_bound(nums.begin(), nums.end(), nums[0], [](int x, int tar) { return x >= tar; })]() { return it == nums.end() ? nums[0] : *it;}();
    }
};
