class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        auto pre_max = vector(n, nums[0]);
        int suf_min = INT_MAX;
        for(int i = 1;i < n;i++) {
            pre_max[i] = max(nums[i], pre_max[i - 1]);
        }
        auto res = vector(n, 0);
        res[n - 1] = pre_max[n - 1];
        for(int i = n - 1;i >= 0;i--) {
            res[i] = suf_min >= pre_max[i] ? pre_max[i] : res[i + 1];
            suf_min = min(suf_min, nums[i]);
        }
        return res;
    }
};
