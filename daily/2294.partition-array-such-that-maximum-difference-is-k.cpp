#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans = 1;
        sort(nums.begin(), nums.end());
        for(int p = nums[0], i = 0; i < nums.size(); i++) {
            if(nums[i] - p > k) {
                p = nums[i];
                ans++;
            }
        }
        return ans;
    }
};