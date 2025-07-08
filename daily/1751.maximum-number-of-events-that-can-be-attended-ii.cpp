#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        ranges::sort(events, [](const auto& a, const auto& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]) || (a[0] == b[0] && a[1] == b[1] && a[2] < b[2]);
        });

        vector<vector<int>> dp(k + 1, vector<int>(events.size(), -1));

        auto dfs = [&](auto&& dfs, int i, int k) -> int {
            if(i == events.size() || k == 0) return 0;
            if(dp[k][i] != -1) return dp[k][i];

            int res = dfs(dfs, i + 1, k);
            auto it = lower_bound(events.begin() + i + 1, events.end(), events[i][1], [](const auto& a, int x) {
                return a[0] < x;
            });

            if(it != events.end()) res = max(res, events[i][2] + dfs(dfs, it - events.begin(), k - 1));
            else res = max(res, events[i][2]);
            return dp[k][i] = res;
        };

        return dfs(dfs, 0, k);
    }
};
