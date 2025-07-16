#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int maximumLength(vector<int>& nums) {
            bool first = nums[0] & 1;
            vector<int> dp(3, 0);
            for(auto x: nums | views::transform([](int x) { return x & 1; })) {
                dp[x] += 1;
                dp[2] += (dp[2] & 1) ^ x;
            }
            return ranges::max(dp);
        }
    };
