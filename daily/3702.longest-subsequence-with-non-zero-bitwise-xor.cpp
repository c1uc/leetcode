class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool az = true;
        int res = 0, n = nums.size();
        for(auto x: nums) {
            az &= (x == 0);
            res ^= x;
        }
        return res == 0 ? (az ? 0 : n - 1) : n;
    }
};
