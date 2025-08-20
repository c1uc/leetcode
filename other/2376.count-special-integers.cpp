#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int countSpecialNumbers(int n) {
            string s = to_string(n);
            vector dp(s.size(), vector<int>(1 << 10, -1));
            auto dfs = [&](this auto&& dfs, int i, int mask, bool is_limit, bool is_num) -> int {
                if(i == s.size()) return is_num;
                if(!is_limit && dp[i][mask] != -1) return dp[i][mask];
                int res = 0;

                if(!is_num) res += dfs(i + 1, mask, false, false);

                int low = is_num ? 0 : 1;
                int high = is_limit ? s[i] - '0' : 9;

                for(int d = low; d <= high; d++) {
                    if(mask & (1 << d)) continue;
                    res += dfs(i + 1, mask | (1 << d), is_limit && d == high, true);
                }
                return is_limit ? res : dp[i][mask] = res;
            };
            return dfs(0, 0, true, false);
        }
    };
