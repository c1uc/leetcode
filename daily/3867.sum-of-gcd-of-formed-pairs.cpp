class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0;
        for(auto& x: nums) {
            mx = max(x, mx);
            x = gcd(x, mx);
        }
        ranges::sort(nums);
        long long s = 0;
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            s += gcd(nums[l++], nums[r--]);
        }
        return s;
    }
};
