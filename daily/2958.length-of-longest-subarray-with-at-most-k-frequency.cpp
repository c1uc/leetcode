class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = 0, r = 0, res = 0, n = nums.size();
        while(r < n) {
            mp[nums[r++]]++;
            while(mp[nums[r - 1]] > k) {
                mp[nums[l++]]--;
            }
            res = max(res, r - l);
        }
        return res;
    }
};
