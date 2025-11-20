#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int intersectionSizeTwo(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
            });
            int n = intervals.size();
            int ans = 0;
            int last = -1;
            int second_last = -1;
            for (int i = 0; i < n; i++) {
                if (intervals[i][0] > last) {
                    ans += 2;
                    second_last = intervals[i][1] - 1;
                    last = intervals[i][1];
                } else if (intervals[i][0] > second_last) {
                    ans += 1;
                    second_last = min(last, intervals[i][1] - 1);
                    last = intervals[i][1];
                }
            }
            return ans;
        }
    };
