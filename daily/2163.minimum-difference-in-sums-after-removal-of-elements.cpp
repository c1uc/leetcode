#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        long long minimumDifference(vector<int>& nums) {
            int n = nums.size();
            vector<ll> mn(n, 0), mx(n, 0);
            priority_queue<int> left;
            priority_queue<int, vector<int>, greater<int>> right;
            ll sum = 0;
            for(int i = 0; i < n; i++) {
                sum += nums[i];
                left.push(nums[i]);
                if(left.size() > n / 3) {
                    sum -= left.top();
                    left.pop();
                }
                mn[i] = sum;
            }
            sum = 0;
            for(int i = n - 1; i >= 0; i--) {
                sum += nums[i];
                right.push(nums[i]);
                if(right.size() > n / 3) {
                    sum -= right.top();
                    right.pop();
                }
                mx[i] = sum;
            }
            ll ans = LLONG_MAX;
            for(int i = n / 3 - 1; i < (n / 3) * 2; i++) {
                ans = min(ans, mn[i] - mx[i + 1]);
            }
            return ans;
        }
    };
