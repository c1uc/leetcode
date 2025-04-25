#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size(), cnt = 0;
        long long ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            cnt += nums[i] % modulo == k;
            mp[cnt]++;
            ans += mp[(cnt - k + modulo) % modulo];
        }   
        return ans;
    }
};
