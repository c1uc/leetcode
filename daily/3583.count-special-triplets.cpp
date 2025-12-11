#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> cnt, cnt_pair;
        int ans = 0;
        for(auto x: nums) {
            if(cnt_pair[x]) ans = (ans + cnt_pair[x]) % MOD;
            if(cnt[x << 1]) cnt_pair[x << 1] = (cnt_pair[x << 1] + cnt[x << 1]) % MOD;
            cnt[x]++;
        }
        return ans;
    }
};
