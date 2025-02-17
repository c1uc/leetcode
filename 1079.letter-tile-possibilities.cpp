/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector cnt(26, 0);
        int l = 0;
        for (char c : tiles) {
            l += (cnt[c - 'A']++ == 0);
        }

        sort(cnt.begin(), cnt.end(), greater<int>());
        cnt.resize(l);

        auto func = [&](int n, auto self) -> int {
            if (n == 1) {
                return count_if(cnt.begin(), cnt.end(), [](int x) { return x != 0; });
            }

            int t = 0;

            for(int i = 0;i < l;i++) {
                if (cnt[i] == 0) {
                    continue;
                }
                cnt[i]--;
                t += self(n - 1, self);
                cnt[i]++;
            }

            return t;
        };
        int ans = 0;
        for(int i = 1;i <= tiles.size();i++) {
            ans += func(i, func);
        }
        return ans;
    }
};
// @lc code=end

