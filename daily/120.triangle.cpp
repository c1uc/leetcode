#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
            vector<int> dp(n, 0);
            dp[0] = triangle[0][0];
            for(int i = 1; i < n; i++) {
                for(int j = i; j >= 0; j--) {
                    dp[j] = triangle[i][j] + min(j == i ? dp[j - 1] : dp[j], j == 0 ? dp[j] : dp[j - 1]);
                }
            }
            return ranges::min(dp);
        }
    };
