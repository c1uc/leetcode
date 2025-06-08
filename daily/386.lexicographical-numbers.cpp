#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        auto dfs = [&](auto dfs, int x) {
            if(x > n) return;
            ans.push_back(x);
            for(int i = 0;i < 10;i++) {
                dfs(dfs, x * 10 + i);
            }
        };
        for(int i = 1;i < 10;i++) {
            dfs(dfs, i);
        }
        return ans;
    }
};
