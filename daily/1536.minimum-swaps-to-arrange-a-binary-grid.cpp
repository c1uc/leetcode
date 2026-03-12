class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size();
        vector<int> rr(n, -1);
        for(int i = 0;i < n;i++) for(int j = n - 1;j >= 0 && rr[i] == -1;j--) if(grid[i][j]) rr[i] = j;
        for(int i = 0;i < n;i++) {
            if(rr[i] <= i) continue;
            for(int j = i + 1;i <= n;j++) {
                if(j == n) return -1;
                if(rr[j] <= i) {
                    ans += j - i;
                    while(j != i) swap(rr[j], rr[--j]);
                    break;
                }
            }
        }
        return ans;
    }
};
