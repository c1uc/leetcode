/*
 * @lc app=leetcode id=2127 lang=cpp
 *
 * [2127] Maximum Employees to Be Invited to a Meeting
 */

// @lc code=start
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll INF = 1e18;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        const int n = favorite.size();
        vector in_deg(n, 0), chain_len(n, 0), vis(n, 0);
        for(int i = 0;i < n;i++) {
            in_deg[favorite[i]]++;
        }

        queue<int> q;
        for(int i = 0;i < n;i++) if(in_deg[i] == 0) q.emplace(i);
        while(!q.empty()) {
            int x = q.front(), y = favorite[x];
            q.pop();

            vis[x] = 1;

            chain_len[y] = max(chain_len[y], chain_len[x] + 1);
            in_deg[y]--;
            if(in_deg[y] == 0) q.emplace(y);
        }

        int ans = 0;
        int ans_2 = 0;

        auto dfs = [&](int x, auto self) -> int {
            vis[x] = 1;
            if(!vis[favorite[x]]) return self(favorite[x], self) + 1;
            return 1;
        };

        for(int i = 0;i < n;i++) {
            if(vis[i]) continue;
            int l = dfs(i, dfs);
            if(l == 2) ans_2 += 2 + chain_len[i] + chain_len[favorite[i]];
            ans = max(ans, l);
        }
        return max(ans, ans_2);
    }
};
// @lc code=end

