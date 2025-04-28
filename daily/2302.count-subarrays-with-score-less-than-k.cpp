#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int l = 0, r = 0;
        long long ans = 0, sum = 0;
        while (r < n) {
            sum += nums[r];
            while (l <= r && sum * (r - l + 1) >= k) {
                sum -= nums[l];
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
};
