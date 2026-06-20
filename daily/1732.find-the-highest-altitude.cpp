class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        return ranges::fold_left(gain, pair<int, int>{0, 0}, [](pair<int, int> acc, int g) -> pair<int, int> { return pair<int, int>{max(acc.first, acc.second + g), acc.second + g}; }).first;
    }
};
