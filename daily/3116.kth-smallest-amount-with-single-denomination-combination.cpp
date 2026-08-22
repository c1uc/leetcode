class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        ranges::sort(coins);
        vector<int> filtered;
        for(auto x: coins) if(filtered.size() == 0 || ranges::none_of(filtered, [&](int c) { return x % c == 0; })) filtered.emplace_back(x);
        int n = filtered.size();
        vector<long long> grp_lcm(1 << n, 1);
        for(int i = 0;i < n;i++) {
            int b = 1 << i;
            for(int msk = 0;msk < b;msk++) {
                grp_lcm[msk | b] = lcm(grp_lcm[msk], filtered[i]);
            }
        }
        auto chk = [&](long long x) {
            long long rem = 0;
            for(int msk = 1;msk < (1 << n);msk++) {
                if(grp_lcm[msk] > x) continue;
                if(__builtin_popcount(msk) % 2) rem += x / grp_lcm[msk];
                else rem -= x / grp_lcm[msk];
            }
            return rem >= k;
        };
        long long l = k - 1, r = 1ll * filtered[0] * k;
        while(l + 1 < r) {
            long long mid = (l + r) >> 1;
            // cout << mid << ' ' << chk(mid) << endl;
            if(chk(mid)) r = mid;
            else l = mid;
        }
        return r;
    }
};
