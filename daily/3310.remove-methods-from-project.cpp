class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> vis(n, 0);
        vector g(n, vector<int>());
        for(auto& edge: invocations) {
            int p = edge[0], q = edge[1];
            g[p].emplace_back(q);
        }
        auto bfs = [&](int x, int f) {
            if(vis[x] != 0) return vis[x] == f ? 1 : -1;
            queue<int> q;
            while(!q.empty()) q.pop();
            q.emplace(x);
            vis[x] = f;
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(auto v: g[u]) {
                    if(vis[v] != 0) {
                        if(vis[v] == f) continue;
                        return -1;
                    }
                    vis[v] = f;
                    q.emplace(v);
                }
            }
            return 1;
        };
        bfs(k, 2);
        for(int i = 0;i < n;i++) if(vis[i] == 0 && bfs(i, 1) == -1) return views::iota(0, n) | ranges::to<vector<int>>();
        vector<int> res;
        for(int i = 0;i < n;i++) if(vis[i] != 2) res.emplace_back(i);
        return res;
    }
};
