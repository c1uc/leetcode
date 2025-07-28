#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int countMaxOrSubsets(vector<int>& nums) {
            int maxOr = 0;
            for (int num : nums) maxOr |= num;
            int ans = 0;
            for (int i = 0; i < (1 << nums.size()); i++) {
                int cur = 0;
                for (int j = 0; j < nums.size(); j++) if (i & (1 << j)) cur |= nums[j];
                if (cur == maxOr) ans++;
            }
            return ans;
        }
    };
