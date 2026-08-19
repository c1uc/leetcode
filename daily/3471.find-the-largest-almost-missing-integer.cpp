class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n) return ranges::max(nums);
        if(k == 1) {
            int cnt[51] = {0};
            for(auto x: nums) cnt[x]++;
            for(int i = 50;i >= -1;i--) {
                if(i == -1 || cnt[i] == 1) return i;
            }
        }
        if(nums[0] == nums[n - 1]) return -1;
        bool f = true, r = true;
        for(int i = 1;i < n - 1;i++) {
            if(nums[i] == nums[0]) f = false;
            if(nums[i] == nums[n - 1]) r = false;
        }
        return [&, a = nums[0], b = nums[n - 1]](){ return f && r ? max(a, b) : (f ? a : (r ? b : -1)); }(); 
    }
};
