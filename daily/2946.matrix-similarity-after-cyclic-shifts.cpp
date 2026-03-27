class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        return ranges::all_of(mat, [k](const auto& r) { return ranges::all_of(views::iota(0, (int)r.size()), [&](int j) { return r[j] == r[(j + k) % r.size()]; }); });
    }
};
