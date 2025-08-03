#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
            int l = ranges::lower_bound(fruits, startPos - k, {}, [](auto &x) { return x[0]; }) - fruits.begin();
            int sum = 0, r = l, n = fruits.size();
            for(;r < fruits.size() && fruits[r][0] <= startPos;r++) {
                sum += fruits[r][1];
            }
            int ans = sum;
            for(; r < n && fruits[r][0] - startPos <= k;r++) {
                sum += fruits[r][1];
                while(((fruits[r][0] - startPos) << 1) + (startPos - fruits[l][0]) > k &&
                 ((startPos - fruits[l][0]) << 1) + (fruits[r][0] - startPos) > k) {
                    sum -= fruits[l][1];
                    l++;
                }
                ans = max(ans, sum);
            }
            return ans;
        }
    };
