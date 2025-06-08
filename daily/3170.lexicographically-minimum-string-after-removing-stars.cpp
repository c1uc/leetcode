#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<vector<int>> pos(26, vector<int>());
        vector<char> ans(s.begin(), s.end());
        int v = 0;
        for(int i = 0;i < n;i++) {
            if(ans[i] == '*') {
                ans[i] = '-';
                int lowbit = __builtin_ctz(v);
                ans[pos[lowbit].back()] = '-';
                pos[lowbit].pop_back();
                if(pos[lowbit].empty()) {
                    v &= ~(1 << lowbit);
                }
            } else {
                pos[ans[i] - 'a'].push_back(i);
                v |= 1 << (ans[i] - 'a');
            }
        }
        return ans | ranges::views::filter([](char c) { return c != '-'; }) | ranges::to<string>();
    }
};