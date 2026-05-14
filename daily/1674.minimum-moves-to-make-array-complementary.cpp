const int LIM = 1e5;
static int df[2 * LIM + 2];

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        memset(df, 0, sizeof(df));
        int n = nums.size();
        df[2] = df[2 * limit] = n;
        for(int i = 0;i < n / 2;i++) {
            int x = nums[i], y = nums[n - i - 1];
            if(x > y) swap(x, y);
            df[1 + x] -= 1;
            df[limit + y + 1] += 1;
            df[x + y] -= 1;
            df[x + y + 1] += 1;
        }
        int s = 0, res = n;
        for(int x = 2;x <= 2 * limit;x++) {
            s += df[x];
            res = min(res, s);
        }
        return res;
    }
};
