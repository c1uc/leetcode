class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0, n = colors.size();
        for(auto [i, c] : colors | views::enumerate) {
            if(c != colors[0]) ans = max(ans, (int)i);
            if(c != colors[n - 1]) ans = max(ans, n - 1 - (int)i);
        }
        return ans;
    }
};
