class Solution {
public:
    int earliestFinishTime(vector<int>& s1, vector<int>& d1, vector<int>& s2, vector<int>& d2) {
        auto solve = [](vector<int>& s1, vector<int>& s2, vector<int>& d1, vector<int>& d2) -> int {
            int t = 2e5 + 2 , res = 4e5 + 2;
            for(auto [s, d]: views::zip(s1, d1)) t = min(t, s + d);
            for(auto [s, d]: views::zip(s2, d2)) res = min(res, max(t, s) + d);
            return res;
        };
        return min(solve(s1, s2, d1, d2), solve(s2, s1, d2, d1));
    }
};
