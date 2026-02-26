class Solution {
public:
    int countBinarySubstrings(string s) {
        return std::ranges::fold_left(
            s 
            | views::chunk_by(std::equal_to<>{}) 
            | views::transform([](auto g) { return ranges::distance(g); }) 
            | views::slide(2) 
            | views::transform([](auto x) { 
                auto it = x.begin();
                int first = *it;
                int second = *std::ranges::next(it);
                return min(first, second); 
            }),
            0, std::plus<>{});
    }
};
