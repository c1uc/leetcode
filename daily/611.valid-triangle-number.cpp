#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

class Solution {
    public:
        int triangleNumber(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int ans = 0, ptr = 0;
            for(int i = 0; i < nums.size(); i++) {
                for(int j = i + 1; j < nums.size(); j++) {
                    while(ptr < nums.size() && nums[ptr] < nums[i] + nums[j]) {
                        ptr++;
                    }
                    ans += ptr - j - 1;
                }
            }
            return ans;
        }
    };
