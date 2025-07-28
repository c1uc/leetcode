#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int maxSum(vector<int>& nums) {
            int max_num = *max_element(nums.begin(), nums.end());
            if (max_num < 0) return max_num;
            vector<int> present(max_num + 1, 0);
            int ans = 0;
            for(auto x: nums) {
                if(x >= 0 && !present[x]) {
                    present[x] = 1;
                    ans += x;
                }
            }
            return ans;
        }
    };