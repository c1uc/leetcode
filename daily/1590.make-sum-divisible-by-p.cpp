#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minSubarray(vector<int>& nums, int p) {
            int n = nums.size(), rem = accumulate(nums.begin(), nums.end(), 0) % p;
            if(rem == 0) return 0;
            unordered_map<int, int> mp;
            mp[0] = -1;
            int ans = n, sum = 0;
            for(int i = 0; i < n; i++) {
                sum = (sum + nums[i]) % p;
                int need = (sum - rem + p) % p;
                if(mp.count(need)) {
                    ans = min(ans, i - mp[need]);
                }
                mp[sum] = i;
            }
            return ans == n ? -1 : ans;
        }
    };
