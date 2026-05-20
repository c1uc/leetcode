using pii = pair<int, int>;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> vis(n, false);
        unordered_map<int, vector<int>> mp;
        for(auto [i, x]: arr | views::enumerate) mp[x].emplace_back(i);
        queue<pii> q;
        q.emplace(0, 0);
        vis[0] = true;
        while(!q.empty()) {
            auto [t, idx] = q.front();
            q.pop();
            if(idx == n - 1) return t;
            auto add = [&](int x) {
                vis[x] = true;
                q.emplace(t + 1, x);
            };

            if(idx > 0 && !vis[idx - 1]) add(idx - 1);
            if(idx < n - 1 && !vis[idx + 1]) add(idx + 1);
            if(mp[arr[idx]].size() > 0) {
                for(auto ii: mp[arr[idx]]) {
                    if(!vis[ii]) add(ii);
                }
                mp[arr[idx]].clear();
            }
        }
        return -1;
    }
};
