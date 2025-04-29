#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0, l = 0, r = 0;
        int max = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        while(r < n) {
            cnt += nums[r] == max;
            r++;
            while(l < r && cnt >= k) {
                if(nums[l] == max) cnt--;
                l++;
                ans += n - r + 1;
            }
        }
        return ans;
    }
};
