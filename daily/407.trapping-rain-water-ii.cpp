using pii = pair<int, int>;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size();
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int vis[n][m];
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                vis[i][j] = 0;
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    vis[i][j] = 1;
                }
            }
        }
        int ans = 0;
        while(!pq.empty()) {
            auto [h, p] = pq.top();
            pq.pop();
            for(int i = 0;i < 4;i++) {
                int x = p.first + dirs[i][0], y = p.second + dirs[i][1];
                if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]) {
                    vis[x][y] = 1;
                    ans += max(0, h - heightMap[x][y]);
                    pq.push({max(h, heightMap[x][y]), {x, y}});
                }
            }
        }
        return ans;
    }
};