using pii = pair<long long, long long>;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size(), l = 0, r = 0;
        auto g = vector(n, vector<pii>());
        for(auto e: edges) {
            int p = e[0], q = e[1], v = e[2];
            g[p].emplace_back(q, v);
            r = max(r, v + 1);
        }
        auto chk = [&](int x) -> bool {
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            pq.emplace(0, 0);
            vector<bool> vis(n, false);
            while(!pq.empty()) {
                auto [c, u] = pq.top();
                pq.pop();
                if(vis[u]) continue;
                vis[u] = true;
                for(auto [v, w]: g[u]) {
                    if(!online[v] || w < x || w + c > k) continue;
                    if(v == n - 1) return true;
                    pq.emplace(c + w, v);
                }
            }
            return false;
        };
        if(!chk(0)) return -1;
        while(l + 1 < r) {
            int m = (l + r) >> 1;
            if(chk(m)) l = m;
            else r = m;
        }
        return l;
    }
};
