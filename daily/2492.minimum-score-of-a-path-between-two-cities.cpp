class DSU {
    public:
    vector<int> pa, sz, mn;
    DSU(int n): pa(n), sz(n, 1), mn(n, 1e4 + 1) {
        ranges::iota(pa, 0);
        return;
    }
    int find(int x) {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }
    bool merge(int x, int y, int d) {
        x = find(x), y = find(y);
        mn[x] = min({mn[x], mn[y], d});
        if(x == y) return false;
        if(sz[x] < sz[y]) swap(x, y);
        pa[y] = x;
        sz[x] += sz[y];
        mn[x] = min({mn[x], mn[y], d});
        return true;
    }
    int query(int x) {
        return mn[find(x)];
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n + 1);
        for(const auto& r: roads) {
            dsu.merge(r[0], r[1], r[2]);
        }
        return dsu.query(n);
    }
};
