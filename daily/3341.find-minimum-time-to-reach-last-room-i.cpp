#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> ti;


class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        priority_queue<ti, vector<ti>, greater<ti>> pq;
        pq.push({0, 0, 0});
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        while (!pq.empty()) {
            auto [d, x, y] = pq.top(); pq.pop();
            if (x == m - 1 && y == n - 1) return d;
            for (auto [dx, dy] : vector<pii>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int nd = max(d, moveTime[nx][ny]) + 1;
                if (nd < dist[nx][ny]) {
                    dist[nx][ny] = nd;
                    pq.push({nd, nx, ny});
                }
            }
        }
        return -1;
    }
};
