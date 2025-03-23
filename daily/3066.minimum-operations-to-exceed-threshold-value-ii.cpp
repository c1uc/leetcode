/*
 * @lc app=leetcode id=3066 lang=cpp
 *
 * [3066] Minimum Operations to Exceed Threshold Value II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        priority_queue<ll, vector<ll>, greater<>> pq;
        for(auto x: nums) pq.push(x);
        while(pq.top() < k) {
            ans++;
            ll p = pq.top();
            pq.pop();
            ll q = pq.top();
            pq.pop();
            pq.push(2ll * p + q);
        }
        return ans;
    }
};
// @lc code=end

