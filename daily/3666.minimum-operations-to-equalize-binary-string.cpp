class Solution {
public:
    int minOperations(string s, int k) {
        set<int> ss[2];
        int n = s.size();
        for(int x = 0;x < 2;x++) {
            for(int i = x;i <= n;i += 2) ss[x].insert(i);
            ss[x].insert(n + 1);
        }
        int st = ranges::count(s, '0');
        ss[st & 1].erase(st);
        vector<int> q = {st};
        for(int t = 0;!q.empty();t++) {
            vector<int> nxt;
            for(auto x: q) {
                if(x == 0) return t;
                int mn = x + k - 2 * min(k, x);
                int mx = x + k - 2 * max(0, k - n + x);
                auto& v = ss[mn & 1];
                for(auto it = v.lower_bound(mn);*it <= mx;it = v.erase(it)) {
                    nxt.emplace_back(*it);
                }
            }
            q = move(nxt);
        }
        return -1;
    }
};
