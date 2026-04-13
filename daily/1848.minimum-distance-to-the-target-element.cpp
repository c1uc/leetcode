class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        return ranges::min(
            nums | views::enumerate |
            views::filter([&](auto p) { return get<1>(p) == target; }) |
            views::transform([&](auto p) { return abs(get<0>(p) - start); }));
    }
};
