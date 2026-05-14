class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        ranges::sort(tasks, [](const auto a, const auto b) { auto df1 = a[1] - a[0], df2 = b[1] - b[0]; return df1 > df2 ? true : (df1 == df2 && a[1] > b[1]); });
        int res = 0, cur = 0;
        for(auto v: tasks) {
            if(cur < v[1]) {
                res += v[1] - cur;
                cur = v[1];
            }
            cur -= v[0];
        }
        return res;
    }
};
