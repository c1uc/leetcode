/*
 * @lc app=leetcode id=2948 lang=cpp
 *
 * [2948] Make Lexicographically Smallest Array by Swapping Elements
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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        unordered_map<int, int> g;
        unordered_map<int, int> ptr;
        vector sorted = nums;
        sort(sorted.begin(), sorted.end());

        int idx = 0;
        for(int i = 1;i < sorted.size();i++) {
            if(sorted[i] - sorted[i - 1] > limit) {
                idx = i;
                ptr[idx] = i;
            }
            g[sorted[i]] = idx;
        }

        vector ans(nums.size(), 0);
        for(int i = 0;i < nums.size();i++) {
            ans[i] = sorted[ptr[g[nums[i]]]++];
        }
        return ans;
    }
};
// @lc code=end

