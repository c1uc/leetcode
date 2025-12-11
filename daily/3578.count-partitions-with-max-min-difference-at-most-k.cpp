#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
    public:
        int countPartitions(vector<int>& nums, int k) {
            int n = nums.size();
            long long sum = 0;
            deque<int> min_q, max_q;
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            int l = 0;
            for(int i = 0; i < n; i++) {
                sum += dp[i];
                while(!min_q.empty() && nums[min_q.back()] > nums[i]) {
                    min_q.pop_back();
                }
                while(!max_q.empty() && nums[max_q.back()] < nums[i]) {
                    max_q.pop_back();
                }
                min_q.push_back(i);
                max_q.push_back(i);
                while(l < i && nums[max_q.front()] - nums[min_q.front()] > k) {
                    sum -= dp[l];
                    l++;
                    if(min_q.front() < l) {
                        min_q.pop_front();
                    }
                    if(max_q.front() < l) {
                        max_q.pop_front();
                    }
                }
                dp[i + 1] = sum % MOD;
            }
            return dp[n];
        }
    };
