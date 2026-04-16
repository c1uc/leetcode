class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> dist(n, INT_MAX);
        vector<pair<int, int>> arr(1e6 + 1, {-1, -1});
        for(int i = 0;i < n;i++) {
            int x = nums[i];
            auto& [f, l] = arr[x];
            if(f == -1) f = i;
            else if(l == -1) {
                dist[i] = min(i - f, n - i + f);
                dist[f] = min(i - f, n - i + f);
                l = i;
            } else {
                dist[i] = min({i - l, n + f - i});
                dist[l] = min({dist[l], i - l});
                dist[f] = min({dist[f], n + f - i});
                l = i;
            }
        }
        return queries | views::transform([&](int x) { return dist[x] != INT_MAX ? dist[x] : -1; }) | ranges::to<vector>();
    }
};
