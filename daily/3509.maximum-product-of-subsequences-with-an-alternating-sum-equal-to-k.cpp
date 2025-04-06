#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        int n = nums.size();
        
        unordered_map<int, unordered_set<int>> dp_odd;
        unordered_map<int, unordered_set<int>> dp_even;

        for(int i = 0;i < n;i++) {
            unordered_map<int, unordered_set<int>> tmp;

            for(auto& [sum, ss] : dp_odd) {
                for(auto& product : ss) {
                    tmp[sum - nums[i]].insert(product * nums[i] > limit ? limit + 1 : product * nums[i]);
                }
            }

            for(auto& [sum, ss] : dp_even) {
                for(auto& product : ss) {
                    dp_odd[sum + nums[i]].insert(product * nums[i] > limit ? limit + 1 : product * nums[i]);
                }
            }

            for(auto& [sum, ss] : tmp) {
                for(auto& product : ss) {
                    dp_even[sum].insert(product);
                }
            }

            dp_odd[nums[i]].insert(nums[i] > limit ? limit + 1 : nums[i]);
        }

        int ans = -1;
        if(dp_odd.find(k) != dp_odd.end()) {
            for(auto& product : dp_odd[k]) {
                if(product <= limit) {
                    ans = max(ans, product);
                }
            }
        }

        if(dp_even.find(k) != dp_even.end()) {
            for(auto& product : dp_even[k]) {
                if(product <= limit) {
                    ans = max(ans, product);
                }
            }
        }

        return ans;
    }
};
