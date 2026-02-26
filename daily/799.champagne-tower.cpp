class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> v(query_row + 1, 0.0);
        v[0] = poured;
        for(int i = 1;i <= query_row;i++) {
            for(int j = i;j >= 0;j--) {
                v[j] = (max(v[j] - 1, 0.0) + max((j ? v[j - 1] - 1 : 0), 0.0)) / 2;
            }
        }
        return v[query_glass] >= 1.0 ? 1.0 : v[query_glass];
    }
};
