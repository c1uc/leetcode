class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& res) {
        int m = res.size();
        if(m == 0) return n - 1;
        ranges::sort(res, {}, [](const auto& v) { return v[0]; });
        vector<int> h(m);
        h[0] = min(res[0][0] - 1, res[0][1]);
        for(int i = 1;i < m;i++) {
            h[i] = min(res[i][1], h[i - 1] + (res[i][0] - res[i - 1][0]));
        }
        for(int i = m - 2;i >= 0;i--) {
            h[i] = min(h[i], h[i + 1] + (res[i + 1][0] - res[i][0]));
        }
        int ans = max((res[0][0] - 1 + h[0]) / 2, h[m - 1] + n - res[m - 1][0]);
        for(int i = 1;i < m;i++) {
            ans = max(ans, (res[i][0] - res[i - 1][0] + h[i] + h[i - 1]) / 2);
        }
        return ans;
    }
};
