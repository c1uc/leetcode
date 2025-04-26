#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        int left = 0, right = 0;
        int minPos = -1, maxPos = -1;

        while (right < n) {
            if (nums[right] == minK) minPos = right;
            if (nums[right] == maxK) maxPos = right;

            if (nums[right] < minK || nums[right] > maxK) {
                left = right + 1;
                minPos = -1;
                maxPos = -1;
            }

            if (minPos != -1 && maxPos != -1) {
                ans += min(minPos, maxPos) - left + 1;
            }

            right++;
        }
        return ans;
    }
};
