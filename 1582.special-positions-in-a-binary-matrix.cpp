class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> r(101, 0), c(101, 0);
        int m = mat.size(), n = mat[0].size();
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                r[i] += mat[i][j];
                c[j] += mat[i][j];
            }
        }
        int ans = 0;
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                ans += mat[i][j] && (r[i] == 1) && (c[j]) == 1;
            }
        }
        return ans;
    }
};
