class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rev) {
        ranges::sort(rev, [](const auto& a, const auto& b) { return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]); });
        int cur = 1, msk = 0, ans = 0;
        auto conv = [](int x) {
            int r = 0;
            if((x & 0b1111111100) == 0) return 2;
            if((x & 0b111100) == 0 || (x & 0b11110000) == 0 || (x & 0b1111000000) == 0) return 1;
            return 0;
        };
        for(auto r: rev) {
            int c = r[0], x = r[1];
            if(c > cur) {
                ans += conv(msk);
                ans += 2 * (c - cur - 1);
                cur = c;
                msk = 0;
            }
            msk |= 1 << x;
        }
        return ans + conv(msk) + 2 * (n - cur);
    }
};
