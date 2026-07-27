class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        ranges::nth_element(nums, ranges::next(nums.begin(), n - 3));
        int mx = max({nums[n - 1], nums[n - 2], nums[n - 3]});
        ranges::nth_element(nums, ranges::next(nums.begin(), 1));
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], mx * nums[0] * nums[1]);
    }
};
