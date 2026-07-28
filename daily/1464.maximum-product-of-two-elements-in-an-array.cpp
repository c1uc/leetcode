class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        ranges::nth_element(nums, ranges::next(nums.begin(), n - 2));
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};
