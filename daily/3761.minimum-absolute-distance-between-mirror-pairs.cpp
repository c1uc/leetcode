class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        auto rev = [](int x) {
            int res = 0;
            while(x) {
                res = res * 10 + x % 10;
                x /= 10;
            }
            return res;
        };
        int ans = INT_MAX;
        for(auto [i, x]: nums | views::enumerate) {
            auto it = mp.find(x);
            if(it != mp.end()) ans = min(ans, (int)i - it->second);
            mp[rev(x)] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
