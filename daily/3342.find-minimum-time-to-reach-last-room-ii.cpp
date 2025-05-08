#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int, int> ti;


class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        priority_queue<ti, vector<ti>, greater<ti>> pq;
        pq.push({0, 0, 0, 0});
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;
        while (!pq.empty()) {
            auto [d, x, y, t] = pq.top(); pq.pop();
            if (x == m - 1 && y == n - 1) return d;
            for (auto [dx, dy] : vector<pii>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int nd = max(d, moveTime[nx][ny]) + (t + 1);
                if (vis[nx][ny]) continue;
                vis[nx][ny] = true;
                pq.push({nd, nx, ny, !t});
            }
        }
        return -1;
    }
};
