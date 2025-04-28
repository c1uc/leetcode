#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pii> sorted_nums;
        for(int i = 0; i < n; i++) {
            sorted_nums.push_back({nums[i], i});
        }
        sort(sorted_nums.begin(), sorted_nums.end());
        
        vector<int> sorted_nums_idx(n);
        for(int i = 0; i < n; i++) {
            sorted_nums_idx[sorted_nums[i].second] = i;
        }

        vector<int> group(n, 0);
        for(int i = 0; i < n; i++) {
            if(i == 0 || sorted_nums[i].first - sorted_nums[i - 1].first > maxDiff) {
                group[i] = i;
            } else {
                group[i] = group[i - 1];
            }
        }

        vector<int> max_hop(n, 0);
        int cur = 0;
        for(int i = 0; i < n; i++) {
            while(cur + 1 < n && sorted_nums[cur + 1].first - sorted_nums[i].first <= maxDiff) {
                cur++;
            }
            max_hop[i] = cur;
        }

        vector<vector<int>> dp(n, vector<int>(20, 0));
        for(int i = 0; i < n; i++) {
            dp[i][0] = max_hop[i];
        }

        for(int j = 1; j < 20; j++) {
            for(int i = 0; i < n; i++) {
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }

        vector<int> ans;
        for(auto& q : queries) {
            int u = q[0], v = q[1];


            if(u == v) {
                ans.push_back(0);
                continue;
            }

            int su = sorted_nums_idx[u], sv = sorted_nums_idx[v];
            if(su > sv) {
                swap(su, sv);
            }

            if(group[su] != group[sv]) {
                ans.push_back(-1);
                continue;
            }

            if(sorted_nums[sv].first - sorted_nums[su].first <= maxDiff) {
                ans.push_back(1);
                continue;
            }

            int cur = su;
            int hops = 0;
            for(int j = 19; j >= 0; j--) {
                if(dp[cur][j] < sv) {
                    cur = dp[cur][j];
                    hops += 1 << j;
                }
            }
            ans.push_back(hops + 1);
        }

        return ans;
    }
};
