class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n;
        while(l + 1 < r) {
            int m = (l + r) >> 1;
            if(nums[m] == target) return m;
            if(nums[m] < nums[l]) {
                if(nums[m] <= target && target <= nums[r - 1]) l = m;
                else r = m;
            } else {
                if(nums[m] > target && nums[l] <= target) r = m;
                else l = m;
            }
        }
        return target == nums[l] ? l : -1;
    }
};
