class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = ranges::max(nums);
        auto cnt = vector<int>(mx + 1, 0);
        for(auto x: nums) cnt[x]++;
        vector<long long> gcd_cnt(mx + 1, 0);
        for(auto x = mx; x > 0;x--) {
            long long s = 0;
            for(int k = x;k <= mx;k += x) s += cnt[k];
            gcd_cnt[x] = s * (s - 1) / 2;
            for(int k = x + x;k <= mx;k += x) gcd_cnt[x] -= gcd_cnt[k];
        }
        for(int i = 1;i <= mx;i++) gcd_cnt[i] += gcd_cnt[i - 1];
        return queries | views::transform([&](long long x) { return ranges::upper_bound(gcd_cnt, x) - gcd_cnt.begin(); }) | ranges::to<vector<int>>();
    }
};
