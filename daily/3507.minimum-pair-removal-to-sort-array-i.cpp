#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr int INF = 1e9;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        auto is_sorted = [&](vector<int>& nums) {
            for(int i = 0;i < nums.size() - 1;++i) {
                if(nums[i] > nums[i + 1]) return false;
            }
            return true;
        };
        int ans = 0;
        while(!is_sorted(nums)) {
            int min_sum = INF, idx = -1;
            for(int i = 0;i < nums.size() - 1;++i) {
                if(nums[i] + nums[i + 1] < min_sum) {
                    min_sum = nums[i] + nums[i + 1];
                    idx = i;
                }
            }
            nums[idx] += nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            ans++;
        }
        return ans;
    }
};
