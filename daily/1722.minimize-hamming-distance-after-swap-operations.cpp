class DSU {
    public:
    vector<int> pa, sz;
    DSU(int n): pa(n), sz(n) {
        iota(pa.begin(), pa.end(), 0);
        return;
    }

    auto find(int x) -> int {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }

    auto unite(int x, int y) -> bool {
        int xx = find(x), yy = find(y);
        if(xx == yy) return false;
        if(sz[xx] > sz[yy]) swap(xx, yy);
        pa[xx] = yy;
        sz[yy] += sz[xx];
        return true;
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& src, vector<int>& tar, vector<vector<int>>& edges) {
        int res = 0, n = src.size();
        DSU u(n);
        for(auto& e: edges) {
            u.unite(e[0], e[1]);
        }
        vector<unordered_map<int, int>> ls(n);
        for(const auto& [i, c]: src | views::enumerate) {
            int x = u.find(i);
            ls[x][c]++;
        }
        for(const auto& [i, c]: tar | views::enumerate) {
            int x = u.find(i);
            auto& mp = ls[x];
            if(ls[x][c]) ls[x][c]--;
            else res++;
        }
        return res;
    }
};
