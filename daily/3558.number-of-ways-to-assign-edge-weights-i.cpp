const int MOD = 1e9 + 7;

auto fpow = [](int x, int p) {
    int res = 1;
    while(p) {
        if(p & 1) res = 1ll * res * x % MOD;
        x = 1ll * x * x % MOD;
        p >>= 1;
    }
    return res;
};

class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for(const auto& v: edges) {
            int p = v[0] - 1, q = v[1] - 1;
            adj[p].emplace_back(q);
            adj[q].emplace_back(p);
        }
        int maxd = 0;
        auto dfs = [&](this auto&& dfs, int x, int pa, int d) -> void {
            if(d > maxd) maxd = d;
            for(const auto& y: adj[x]) {
                if(y != pa) dfs(y, x, d + 1);
            }
        };
        dfs(0, -1, 0);
        return fpow(2, maxd - 1) % MOD;
    }
};
