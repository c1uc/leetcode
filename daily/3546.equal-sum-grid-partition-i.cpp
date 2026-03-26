const int MAXN = 1e5 + 1;
static long long r[MAXN], c[MAXN];

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        long long sum = 0;
        for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) {
            sum += grid[i][j];
            r[i] += grid[i][j];
            c[j] += grid[i][j];
        }
        if(sum & 1) return false;
        sum >>= 1;
        long long s = 0;
        for(int i = 0;i < m;i++) {
            s += r[i];
            if(s == sum) return true;
        }
        s = 0;
        for(int i = 0;i < n;i++) {
            s += c[i];
            if(s == sum) return true;
        }
        return false;
    }
};
