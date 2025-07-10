#include <bits/stdc++.h>
#include <ranges>
using namespace std;


class Solution {
    public:
        int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
            int n = startTime.size();
            auto g = views::iota(0, n + 1) | views::transform([&](int i) { return (i == n ? eventTime : startTime[i + 1]) - (i == 0 ? 0 : endTime[i]); }) | ranges::to<vector<int>>();
            
            ranges::copy(g, ostream_iterator<int>(cout, " "));
            cout << endl;

            vector<int> suf(n, 0);
            for(int i = n - 2; i >= 0; i--) {
                suf[i] = max(suf[i + 1], g[i + 2]);
            }
            int ans = 0, pre = 0;
            for(int i = 0; i < n; i++) {
                int d = endTime[i] - startTime[i];
                if(d <= pre || d <= suf[i]) {
                    ans = max(ans, d + g[i] + g[i + 1]);
                } else {
                    ans = max(ans, g[i] + g[i + 1]);
                }
                pre = max(pre, d);
            }

            return ans;
        }
    };
