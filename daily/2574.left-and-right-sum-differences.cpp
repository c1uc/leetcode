class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            s += nums[i];
            nums[i] += i ? nums[i - 1] : 0;
        }
        for(int i = n - 1;i >= 0;i--) {
            nums[i] = abs(s - nums[i] - (i ? nums[i - 1] : 0));
        }
        return nums;
    }
};
