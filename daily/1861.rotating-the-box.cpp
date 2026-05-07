class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& bg) {
        int m = bg.size(), n = bg[0].size();
        auto res = vector(n, vector(m, '.'));
        for(int i = 0;i < m;i++) {
            int border = n - 1;
            for(int j = n - 1;j >= 0;j--) {
                if(bg[i][j] == '*') {
                    res[j][m - i - 1] = '*';
                    border = j - 1;
                } else if(bg[i][j] == '#') {
                    res[border--][m - i - 1] = '#';
                }
            }
        }
        return res;
    }
};
