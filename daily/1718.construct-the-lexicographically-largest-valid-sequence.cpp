/*
 * @lc app=leetcode id=1718 lang=cpp
 *
 * [1718] Construct the Lexicographically Largest Valid Sequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, 0);
        vector<bool> used(n + 1, false);

        auto f = [&](int i, auto self) -> bool {
            if(i == 2 * n - 1) return true;
            if(ans[i] != 0) return self(i + 1, self);
            for(int j = n; j >= 1; j--) {
                if(used[j]) continue;
                if(j == 1) {
                    ans[i] = j;
                    used[j] = true;
                    if(self(i + 1, self)) return true;
                    ans[i] = 0;
                    used[j] = false;
                } else if(i + j < 2 * n - 1 && ans[i + j] == 0) {
                    ans[i] = ans[i + j] = j;
                    used[j] = true;
                    if(self(i + 1, self)) return true;
                    ans[i] = ans[i + j] = 0;
                    used[j] = false;
                }
            }

            return false;
        };

        f(0, f);
        return ans;
    }
};
// @lc code=end

