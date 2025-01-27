/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */

// @lc code=start
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using lll = bitset<100>;
constexpr ll INF = 1e18;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector preq(numCourses, lll());
        vector edge(numCourses, vector<int>());
        vector in_deg(numCourses, 0);

        for(auto& req: prerequisites) {
            edge[req[0]].emplace_back(req[1]);
            in_deg[req[1]] ++;
        }

        queue<int> q;
        for(int i = 0;i < numCourses;i++) if(in_deg[i] == 0) q.emplace(i);

        while(!q.empty()) {
            int x = q.front();
            q.pop();

            for(auto& y: edge[x]) {
                preq[y] |= preq[x];
                preq[y][x] = 1;
                in_deg[y] --;

                if(in_deg[y] == 0) q.emplace(y);
            }
        }

        vector ans(queries.size(), false);
        for(int i = 0;i < queries.size();i++) {
            ans[i] = preq[queries[i][1]][queries[i][0]];
        }

        return ans;
    }
};
// @lc code=end

