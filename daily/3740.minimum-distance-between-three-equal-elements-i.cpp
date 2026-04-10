class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<vector<int>> vec(101, vector<int>());
        int ans = INT_MAX;
        for(int i = 0;i < nums.size();i++) {
            auto& s = vec[nums[i]];
            s.emplace_back(i);
            if(s.size() >= 3) {
                int n = s.size();
                ans = min(ans, 2 * s[n - 1] - 2 * s[n - 3]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
