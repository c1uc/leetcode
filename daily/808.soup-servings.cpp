#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = (4800 + 24) / 25;
vector<vector<double>> memo(MAXN + 1, vector<double>(MAXN + 1, -1.0));

class Solution {
    public:
        double soupServings(int n) {
            if (n >= 4800) return 1.0;
            int m = (n + 24) / 25;

            auto dfs = [&](this auto&& dfs, int a, int b) -> double {
                if (a <= 0 && b <= 0) return 0.5;
                if (a <= 0) return 1.0;
                if (b <= 0) return 0.0;
                if (memo[a][b] != -1.0) return memo[a][b];
                return memo[a][b] = 0.25 * (dfs(a - 4, b) + dfs(a - 3, b - 1) + dfs(a - 2, b - 2) + dfs(a - 1, b - 3));
            };

            return dfs(m, m);
        }
    };
