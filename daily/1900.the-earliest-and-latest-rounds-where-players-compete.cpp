#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
            vector memo(n + 1, vector(n + 1, vector<pair<int, int>>(n + 1, {-1, -1})));

            auto dfs = [&](this auto&& dfs, int n, int first, int second) -> pair<int, int> {
                if(first + second == n + 1) return {1, 1};

                if(first + second > n + 1) {
                    tie(first, second) = pair(n + 1 - second, n + 1 - first);
                }

                auto& res = memo[n][first][second];
                if(res.first != -1) return res;

                int m = (n + 1) / 2;
                int max_mid = second > m ? m - first : second - first;
                int min_mid = second > m ? second - n / 2 - 1 : 0;

                int mm = INT_MAX, mx = 0;

                for(int left = 0; left < first;left++) {
                    for(int mid = min_mid;mid < max_mid;mid++) {
                        auto [e, l] = dfs(m, left + 1, left + mid + 2);
                        mm = min(mm, e);
                        mx = max(mx, l);
                    }
                }

                return res = {mm + 1, mx + 1};
            };

            auto [e, l] = dfs(n, firstPlayer, secondPlayer);
            return {e, l};
        }
    };
