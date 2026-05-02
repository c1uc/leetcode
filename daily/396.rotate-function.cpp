using ti = tuple<int, int>;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        return get<1>([&, s = accumulate(nums.begin(), nums.end(), 0),
                       t = ranges::fold_left(nums | views::enumerate, 0,
                                             [](int ac, auto p) {
                                                 return ac +
                                                        get<0>(p) * get<1>(p);
                                             }),
                       n = nums.size()]() {
            return ranges::fold_left(nums | views::reverse, ti{t, t},
                                     [&](auto ac, int x) -> ti {
                                         int tt = get<0>(ac) + s - n * x;
                                         return {tt, max(tt, get<1>(ac))};
                                     });
        }());
    }
};
