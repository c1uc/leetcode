#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
            auto calc = [&](int i) {
                return (i == startTime.size() ? eventTime : startTime[i]) - (i > 0 ? endTime[i - 1] : 0);
            };

            int sum = 0, ans = 0;
            for(int i = 0;i <= startTime.size();i++) {
                sum += calc(i);
                ans = max(ans, sum);
                if(i >= k) {
                    sum -= calc(i - k);
                }
            }
            return ans;
        }
    };
