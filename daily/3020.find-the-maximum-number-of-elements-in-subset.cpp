class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> m;
        for(const auto& x: nums) m[x]++;
        int ans = 0;
        for(auto [x, val]: m) {
            if(x == 1) ans = max(ans, (m[1] - 1) | 1);
            else {
                int i = 0;
                long long c = x;
                while(m.contains(c) && m[c] > 1) {
                    i++;
                    c *= c;
                }
                ans = max(ans, 2 * i + (m.contains(c) ? 1 : -1));
            }
        }
        return ans;
    }
};
