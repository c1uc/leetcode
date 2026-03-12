struct DSU {
    int c;
    vector<int> fa, sz;

    DSU(int n) : c(n), fa(n), sz(n) {
        ranges::iota(fa, 0);
        ranges::fill(sz, 1);
    }

    auto find(int x) -> int {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    auto merge(int x, int y) -> bool {
        auto xx = find(x), yy = find(y);
        if(xx == yy) return false;
        if(sz[xx] > sz[yy]) swap(xx, yy);
        fa[xx] = yy;
        sz[yy] += sz[xx];
        c--;
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU res(n), tmp(n);
        int mn = 1e7;
        for(auto& e: edges) {
            int u = e[0], v = e[1], s = e[2], m = e[3];
            if(m) {
                if(!res.merge(u, v)) return -1;
                mn = min(mn, s);
            }
            tmp.merge(u, v);
        }

        if(tmp.c > 1) return -1;
        if(res.c == 1) return mn;
        int c = res.c;

        ranges::sort(edges, greater<int>(), [](auto v) { return v[2]; });
        for(auto& e: edges) {
            int u = e[0], v = e[1], s = e[2], m = e[3];
            if(!m && res.merge(u, v)) {
                mn = min(mn, c <= k + 1 ? s * 2 : s);
                c--;
                if(c == 1) break;
            }
        }
        return mn;
    }
};
