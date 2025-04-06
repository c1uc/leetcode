#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> pii;

class Solution {
public:
    int minimumPairRemoval(vector<int>& a) {
        int n = a.size();

        int rev = 0, ans = 0;
        vector<int> pre(n), nxt(n);
        set<pii> s;
        vector<long long> nums(a.begin(), a.end());

        for(int i = 0;i < n;i++) {
            pre[i] = i - 1;
            nxt[i] = i + 1;
        }

        for(int i = 0;i < n - 1;i++) {
            s.insert({nums[i] + nums[i + 1], i});
            if(nums[i] > nums[i + 1]) {
                rev++;
            }
        }

        while(rev > 0) {
            ans++;
            auto [sum, i] = *s.begin();
            s.erase(s.begin());

            // h, i, j, k
            int j = nxt[i], k = nxt[j], h = pre[i];

            if(nums[i] > nums[j]) {
                rev--;
            }

            if(h >= 0) {
                s.erase({nums[h] + nums[i], h});
                s.insert({nums[h] + sum, h});

                if(nums[h] > nums[i] && nums[h] <= sum) rev--;
                else if(nums[h] <= nums[i] && nums[h] > sum) rev++;
            }

            if(k < n) {
                pre[k] = i;

                s.erase({nums[j] + nums[k], j});
                s.insert({nums[k] + sum, i});

                if(nums[j] > nums[k] && sum <= nums[k]) rev--;
                else if(nums[j] <= nums[k] && sum > nums[k]) rev++;
            }

            nxt[i] = k;
            nums[i] = sum;
        }

        return ans;
    }
};