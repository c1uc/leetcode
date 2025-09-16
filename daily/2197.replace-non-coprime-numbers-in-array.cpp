#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> replaceNonCoprimes(vector<int>& nums) {
            vector<int> ans;
            for(int i = 0;i < nums.size();i++) {
                if(ans.empty() || __gcd(ans.back(), nums[i]) == 1) {
                    ans.push_back(nums[i]);
                } else {
                    int tmp = 1ll * ans.back() * nums[i] / __gcd(ans.back(), nums[i]);
                    ans.pop_back();
                    while(!ans.empty() && __gcd(ans.back(), tmp) != 1) {
                        tmp = ans.back() * tmp / __gcd(ans.back(), tmp);
                        ans.pop_back();
                    }
                    ans.push_back(tmp);
                }
            }
            return ans;
        }
    };
