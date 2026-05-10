const int MAXN = 1e6 + 1;
vector<int> pm [MAXN];

auto init = []() {
    for (int i = 2; i < MAXN; ++i) {
        if (pm[i].empty()) {
            for (int j = i; j < MAXN; j += i) {
                pm[j].push_back(i);
            }
        }
    }
    return 'c';
}();


class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        auto vis = vector(n, false);
        auto bucket = unordered_map<int, vector<int>>();

        for(int i: views::iota(0, n)) {
            auto x = nums[i];
            for(auto p: pm[x]) bucket[p].push_back(i);
        }

        auto q = queue<pair<int, int>>();
        q.push({0, 0});
        while(!q.empty()) {
            auto [t, idx] = q.front();
            q.pop();
            if(idx == n - 1) return t;
            if(vis[idx]) continue;
            vis[idx] = true;

            auto x = nums[idx];

            if(idx > 0 && !vis[idx - 1]) q.push({t + 1, idx - 1});
            if(!vis[idx + 1]) q.push({t + 1, idx + 1});
            if(pm[x].size() == 1 && bucket.count(x)) {
                for(auto ix: bucket[x]) {
                    if(ix == idx || vis[ix]) continue;
                    q.push({t + 1, ix});
                }
                bucket[x].clear();
            }
        }
        return -1;
    }
};
