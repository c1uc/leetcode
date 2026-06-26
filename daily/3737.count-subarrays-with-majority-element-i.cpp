class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> cnt(2 * n + 1, 0);
        int pre = 0, cur = n, ans = 0;
        cnt[n] = 1;
        for(const auto& x: nums) {
            int r = (x == target ? 1 : -1);
            if(r == 1) {
                pre += cnt[cur];
            } else {
                pre -= cnt[cur - 1];
            }
            cur += r;
            cnt[cur]++;
            ans += pre;
        }
        return ans;
    }
};
