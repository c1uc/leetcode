/*
 * @lc app=leetcode id=2375 lang=cpp
 *
 * [2375] Construct Smallest Number From DI String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        string ans(pattern.size() + 1, '0');
        bitset<10> used;

        auto func = [&](int idx, auto self) -> bool {
            if(idx == pattern.size() + 1) {
                return true;
            }
            if(idx == 0) {
                for(int i = 1;i <= pattern.size() + 1;i++) {
                    ans[idx] = i + '0';
                    used[i] = true;
                    if(self(idx + 1, self)) {
                        return true;
                    }
                    used[i] = false;
                }
                return false;
            } else {
                if(pattern[idx - 1] == 'I') {
                    for(int i = ans[idx - 1] - '0' + 1;i <= pattern.size() + 1;i++) {
                        if(used[i]) {
                            continue;
                        }
                        ans[idx] = i + '0';
                        used[i] = true;
                        if(self(idx + 1, self)) {
                            return true;
                        }
                        used[i] = false;
                    }
                } else {
                    for(int i = ans[idx - 1] - '0' - 1;i >= 1;i--) {
                        if(used[i]) {
                            continue;
                        }
                        ans[idx] = i + '0';
                        used[i] = true;
                        if(self(idx + 1, self)) {
                            return true;
                        }
                        used[i] = false;
                    }
                }
                return false;
            }
        };

        func(0, func);
        return ans;
    }
};
// @lc code=end

