#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class DSU {
    public:
        vector<int> p;
    DSU(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        p[x] = y;
    }
};


class Solution {
    public:
        vector<int> avoidFlood(vector<int>& rains) {
            int n = rains.size(), idx = 0;

            unordered_map<int, int> mp;
            vector<int> last(n + 1, -1);
            vector<int> ans(n, -1);
            
            DSU dsu(n + 1);
            for(int i = 0;i < n;i++) {
                if(rains[i]) {
                    dsu.merge(i, i + 1);

                    if(!mp.count(rains[i])) {
                        mp[rains[i]] = idx;
                        last[idx++] = i;
                    } else {
                        int id = mp[rains[i]];
                        int avail = dsu.find(last[id]);
                        if(avail >= i) {
                            return {};
                        } else {
                            ans[avail] = rains[i];
                            dsu.merge(avail, avail + 1);
                        }
                        last[id] = i;
                    }
                } else {
                    ans[i] = 1;
                }
            }

            return ans;
        }
    };
