#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        vector<int> cnt(100, 0);
        for (auto& d : dominoes) {
            int a = d[0], b = d[1];
            if (a > b) swap(a, b);
            ans += cnt[a * 10 + b]++;
        }
        return ans;
    }
};
