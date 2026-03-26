const int MAXN = 1e5 + 1;
static int freq1[MAXN], freq[MAXN];

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        long long sum = 0, s = 0, df, ss;
        fill(freq, freq + MAXN, 0);
        fill(freq1, freq1 + MAXN, 0);
        for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) {
            freq[g[i][j]]++;
            sum += g[i][j];
        }
        for(int j = 0;j < m - 1;j++) {
            for(int i = 0;i < n;i++) {
                s += g[i][j];
                freq1[g[i][j]]++;
            }
            ss = sum - s;
            if(ss == s) return true;
            else if(s > ss) {
                df = s - ss;
                cout << df << ' ';
                if(n == 1) {
                    if(g[0][0] == df || g[0][j] == df) return true;
                }
                else if(j == 0 || m == 2) {
                    if(g[0][0] == df || g[n - 1][0] == df) return true;
                }
                else if(df < MAXN && freq1[df] > 0) return true;
            } else {
                df = ss - s;
                cout << df << ' ';
                if(n == 1) {
                    if(g[0][m - 1] == df || g[0][j + 1] == df) return true;
                }
                else if(j == m - 2 || m == 2) {
                    if(g[0][m - 1] == df || g[n - 1][m - 1] == df) return true;
                }
                else if(df < MAXN && freq[df] - freq1[df] > 0) return true;
            }
        }
        s = 0;
        fill(freq1, freq1 + MAXN, 0);
        for(int i = 0;i < n - 1;i++) {
            for(int j = 0;j < m;j++) {
                s += g[i][j];
                freq1[g[i][j]]++;
            }
            ss = sum - s;
            if(ss == s) return true;
            else if(s > ss) {
                df = s - ss;
                if(m == 1) {
                    if(g[0][0] == df || g[i][0] == df) return true;
                }
                else if(i == 0 || n == 2) {
                    if(g[0][0] == df || g[0][m - 1] == df) return true;
                }
                else if(df < MAXN && freq1[df] > 0) return true;
            } else {
                df = ss - s;
                if(n == 1) {
                    if(g[n - 1][0] == df || g[i + 1][0] == df) return true;
                }
                else if(i == n - 2 || n == 2) {
                    if(g[n - 1][0] == df || g[n - 1][m - 1] == df) return true;
                }
                else if(df < MAXN && freq[df] - freq1[df] > 0) return true;
            }
        }
        return false;
    }
};
