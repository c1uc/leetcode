#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        long long zeroFilledSubarray(vector<int>& nums) {
            ll ans = 0;
            ll left = 0;
            for (int right = 0; right < nums.size(); right++) {
                if (nums[right] == 0) {
                    ans += right - left + 1;
                } else {
                    left = right + 1;
                }
            }
            return ans;
        }
    };
