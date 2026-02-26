const long long ninf = -0x3f3f3f3f3f3f3f3f;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long f1 = ninf, f2 = ninf, f3 = ninf, ans = ninf;
        for(int i = 1;i < nums.size();i++) {
            long long x = nums[i - 1], y = nums[i];
            f3 = y > x ? max(f2, f3) + y : ninf;
            f2 = x > y ? max(f1, f2) + y : ninf;
            f1 = y > x ? max(x, f1) + y : ninf;
            ans = max(ans, f3);
        }
        return ans;
    }
};
