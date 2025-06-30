#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;

        for(int i = 0, j = 0; j < n; j++) {
            if(nums[j] == nums[i]) continue;
            if(nums[j] == nums[i] + 1) {
                int t = j;
                while(j + 1 < n && nums[j + 1] == nums[t]) j++;
                ans = max(ans, j - i + 1);
                i = t;
            } else {
                i = j;
            }
        }
        return ans;
    }
};
