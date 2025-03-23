#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll INF = 1e18;

class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size(), m = properties[0].size(), ans = n;
        vector<int> fa(n);
        iota(fa.begin(), fa.end(), 0);

        auto find = [&](int x, auto &&self) -> int {
            return fa[x] == x ? x : fa[x] = self(fa[x], self);
        };

        vector<bitset<101>> s(n);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                s[i][properties[i][j]] = 1;
            }
        }

        auto check = [&](int x, int y) {
            if((s[x] & s[y]).count() >= k) {
                return true;
            }
            return false;
        };

        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n;j++) {
                if(check(i, j)) {
                    int x = find(i, find);
                    int y = find(j, find);
                    if(x != y) {
                        fa[x] = y;
                        ans--;
                    }
                }
            }
        }
        return ans;
    }
};