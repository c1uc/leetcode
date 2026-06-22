class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        ranges::sort(costs);
        int ans = 0;
        for(const auto& x: costs) {
            if(x > coins) return ans;
            coins -= x;
            ++ans;
        }
        return ans;
    }
};
