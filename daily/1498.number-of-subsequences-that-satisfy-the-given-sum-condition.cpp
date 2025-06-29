#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;
int p[100005];

auto init = []() {
    p[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        p[i] = (p[i - 1] << 1) % MOD;
    }
    return 'c';
}();



class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        ranges::sort(nums);
        int ans = 0;
        for(int i = 0, j = nums.size() - 1; i <= j; i++) {
            while(i <= j && nums[i] + nums[j] > target) {
                j--;
            }
            if(i <= j) {
                ans = (ans + p[j - i]) % MOD;
            }
        }
        return ans;
    }
};
