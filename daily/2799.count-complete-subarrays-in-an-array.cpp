#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(), q = 0, l = 0, r = 0, ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        unordered_map<int, int> cnt;
        int m = s.size();
        while(r < n) {
            if(cnt[nums[r]] == 0) q++;
            cnt[nums[r]]++;
            r++;
            while(q == m) {
                ans += n - r + 1;
                cnt[nums[l]]--;
                if(cnt[nums[l]] == 0) q--;
                l++;
            }
        }
        return ans;
    }
};
