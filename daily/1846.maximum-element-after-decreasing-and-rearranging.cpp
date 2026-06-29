class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        ranges::sort(arr);
        int ans = 0;
        for(auto& x: arr) {
            ans = min(ans + 1, x);
        }
        return ans;
    }
};
