class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        ranges::sort(arr, [](int a, int b) { return __builtin_popcount(a) == __builtin_popcount(b) ? a < b : __builtin_popcount(a) < __builtin_popcount(b); } );
        return arr;
    }
};
