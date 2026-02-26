class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        return ranges::equal(nums 
            | views::slide(2) 
            | views::transform([](auto x) { return x[0] > x[1] ? 1 : (x[0] < x[1] ? -1 : 0); }) 
            | views::chunk_by(std::equal_to<>{}) 
            | views::transform([](auto g) { return g[0]; }), 
            vector{-1, 1, -1});
    }
};
