/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> vis(n);

        pq.push({height[0], 0});
        pq.push({height[n - 1], n - 1});

        vis[0] = vis[n - 1] = 1;

        int ans = 0;
        while(!pq.empty()) {
            auto [h, i] = pq.top();
            pq.pop();

            if(i > 0 && !vis[i - 1]) {
                if(height[i - 1] < h) 
                    ans += h - height[i - 1];

                vis[i - 1] = 1;
                pq.push({max(h, height[i - 1]), i - 1});
            }
            if(i < n - 1 && !vis[i + 1]) {
                if(height[i + 1] < h)
                    ans += h - height[i + 1];
                
                vis[i + 1] = 1;
                pq.push({max(h, height[i + 1]), i + 1});
            }
        }
        return ans;
    }
};
// @lc code=end

