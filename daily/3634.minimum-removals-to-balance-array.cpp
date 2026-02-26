class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        ranges::sort(nums);
        int j = 0, n = nums.size();
        int ans = n - 1;
        for(int i = 0;i < n;i++) {
            while(j < n && nums[j] <= 1ll * k * nums[i]) ++j;
            ans = min(ans, n - j + i);
        }
        return ans;
    }
};
