#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int countHillValley(vector<int>& nums) {
            int prev = nums[0], cur = nums[0], ans = 0, nxt = 1;
            while (nxt < nums.size()) {
                while (nxt < nums.size() && nums[nxt] == cur) nxt++;
                if (nxt == nums.size()) break;
                if ((nums[nxt] > cur && cur > prev) || (nums[nxt] < cur && cur < prev)) ans++;
                prev = cur;
                cur = nums[nxt];
            }
            return ans;
        }
    };
