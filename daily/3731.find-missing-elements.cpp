class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unsigned __int128 bs = 0;
        int mn = 101, mx = 0;
        vector<int> res;
        for(const auto& x: nums) {
            bs |= (unsigned __int128)1 << x;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        for(int i = mn;i <= mx;i++) {
            if(bs & ((unsigned __int128)1 << i)) continue;
            res.emplace_back(i);
        }
        return res;
    }
};
