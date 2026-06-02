class Solution {
public:
    int minimumCost(vector<int>& cost) {
        ranges::sort(cost);
        int res = 0;
        for(auto [i, x]: cost | views::reverse | views::enumerate) res += (i % 3 != 2) * x;
        return res;
    }
};
