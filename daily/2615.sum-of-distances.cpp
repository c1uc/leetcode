using ll = long long;
using pii = pair<ll, ll>;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll> ans(n, 0ll);
        unordered_map<ll, pii> mp;
        for(const auto& [i, x]: nums | views::enumerate) {
            auto it = mp.find(x);
            if(it == mp.end()) mp[x] = {1, i};
            else {
                auto [c, d] = it->second;
                ans[i] = 1ll * i * c - d;
                mp[x] = {c + 1, d + i};
            }
        }
        mp.clear();
        for(const auto& [i, x]: nums | views::reverse | views::enumerate) {
            auto it = mp.find(x);
            if(it == mp.end()) mp[x] = {1, i};
            else {
                auto [c, d] = it->second;
                ans[n - 1 - i] += 1ll * i * c - d;
                mp[x] = {c + 1, d + i};
            }
        }
        return ans;
    }
};
