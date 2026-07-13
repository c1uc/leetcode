class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> rank;
        for (int x : arr) rank[x];
        int r = 0;
        for (auto& [_, v] : rank) v = ++r;
        return arr | views::transform([&](int x){ return rank[x]; })
                   | ranges::to<vector>();
    }
};
