#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int numberOfPairs(vector<vector<int>>& points) {
            sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
                return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
            });
            int ans = 0;
            for(int i = 0; i < points.size(); i++) {
                int prev_y = 51;
                for(int j = i - 1; j >= 0; j--) {
                    if(points[j][0] <= points[i][0] && points[j][1] >= points[i][1] && points[j][1] < prev_y) {
                        prev_y = points[j][1];
                        ans++;
                    }
                }
            }
            return ans;
        }
    };
