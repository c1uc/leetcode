class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        auto h = vector<int>(m, 0);
        int ans = 0;
        for(auto v: matrix) {
            for(int i = 0;i < m;i++) h[i] = v[i] ? h[i] + 1 : 0;
            auto h2 = h;
            ranges::sort(h2, greater<int>());
            for(int i = 0;i < m;i++) ans = max(ans, (i + 1) * h2[i]);
        }
        return ans;
    }
};
