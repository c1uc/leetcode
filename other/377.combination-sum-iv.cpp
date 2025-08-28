#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int combinationSum4(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            auto dp = vector<unsigned long long>(target + 1, 0);
            dp[0] = 1;
            for(int i = 1; i <= target; i++) {
                for(int num : nums) {
                    if(num > i) break;
                    dp[i] += dp[i - num];
                }
            }
            return dp[target];
        }
    };
