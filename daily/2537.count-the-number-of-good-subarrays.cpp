#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size(), pairs = 0, l = 0, r = 0;
        ll ans = 0;
        unordered_map<int, int> mp;
        while(r < n)
        {
            pairs += (mp[nums[r]]++);
            while(pairs >= k)
            {
                ans += n - r;
                pairs -= (--mp[nums[l]]);
                l++;
            }
            r++;
        }
        return ans;
    }
};