#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            auto subarr = nums | views::split(0) | views::transform([](auto&& subarr) {
                return ranges::size(subarr);
            }) | ranges::to<vector<int>>();
            if(subarr.size() == 1 || subarr.size() == 0) {
                return subarr.size() == 0 ? 0 : subarr[0] - 1;
            }
            int ans = 0;
            for(int i = 0;i < subarr.size() - 1;i++) {
                ans = max(ans, subarr[i] + subarr[i + 1]);
            }
            return ans;
        }
    };
