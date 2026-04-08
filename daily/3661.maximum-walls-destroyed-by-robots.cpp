using pii = pair<int, int>;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        vector<pii> vec = {{0, 0}, {1e9 + 1, 0}};
        int lmax, rmax, l, cur, r1, r2, n = robots.size(), m = walls.size();
        lmax = rmax = l = cur = r1 = r2 = 0;
        for(int i = 0;i < n;i++) vec.emplace_back(robots[i], distance[i]);
        ranges::sort(vec);
        ranges::sort(walls);
        for(int i = 1;i <= n;i++) {
            auto [x, d] = vec[i];
            int lpos = max(x - d, vec[i - 1].first + 1);
            while(l < m && walls[l] < lpos) l++;
            while(cur < m && walls[cur] < x) cur++;
            int cur1 = cur;
            if(cur < m && walls[cur] == x) cur++;
            int lres = lmax + cur - l;

            auto [x1, d1] = vec[i + 1];
            int rpos = min(x + d, x1 - d1 - 1);
            while(r1 < m && walls[r1] <= rpos) r1++;
            lmax = max(lres, rmax + r1 - cur1);

            rpos = min(x + d, x1 - 1);
            while(r2 < m && walls[r2] <= rpos) r2++;
            rmax = max(lres, rmax + r2 - cur1);
        }
        return rmax;
    }
};
