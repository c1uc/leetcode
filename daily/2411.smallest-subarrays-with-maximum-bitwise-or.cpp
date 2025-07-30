#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        vector<int> smallestSubarrays(vector<int>& nums) {
            vector<int> bitpos(32, -1);
            vector<int> ans(nums.size(), 1);
            for(int i = nums.size() - 1; i >= 0; i--) {
                for(int j = 0; j < 32; j++) {
                    if(nums[i] & (1 << j)) bitpos[j] = i;
                }
                ans[i] = max(ans[i], *max_element(bitpos.begin(), bitpos.end()) - i + 1);
            }
            return ans;
        }
    };
