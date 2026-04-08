const int MOD = 1e9 + 7;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto q: queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            while(l <= r) {
                nums[l] = 1ll * nums[l] * v % MOD;
                l += k;
            }
        }
        int res = 0;
        for(auto x: nums) res ^= x;
        return res;
    }
};
