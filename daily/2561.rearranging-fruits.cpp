#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        long long minCost(vector<int>& basket1, vector<int>& basket2) {
            map<int, int> cnt;
            for(auto [x, y]: views::zip(basket1, basket2)) {
                cnt[x]++;
                cnt[y]--;
            }
            vi a, b;
            int mm = ranges::min(cnt | views::keys);
            for(auto [k, v]: cnt) {
                if(v == 0) continue;
                if(v & 1) return -1;
                for(auto _ = 0;_ < v >> 1;_++) a.emplace_back(k);
                for(auto _ = 0;_ < (-v) >> 1;_++) b.emplace_back(k);
            }
            sort(a.begin(), a.end());
            sort(b.begin(), b.end(), greater<int>());
            ll ans = 0;
            for(auto i = 0;i < a.size();i++) {
                ans += ranges::min({a[i], b[i], mm << 1});
            }
            return ans;
        }
    };
