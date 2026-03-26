class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bool ch[] = {true, true, true, true};
        for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) {
            if(mat[i][j] != target[i][j]) ch[0] = false;
            if(mat[n - j - 1][i] != target[i][j]) ch[1] = false;
            if(mat[n - i - 1][n - j - 1] != target[i][j]) ch[2] = false;
            if(mat[j][n - i - 1] != target[i][j]) ch[3] = false;
        }
        return ch[0] || ch[1] || ch[2] || ch[3];
    }
};
