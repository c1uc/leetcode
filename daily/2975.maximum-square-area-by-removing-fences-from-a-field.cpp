#include <bits/stdc++.h>
using namespace std;


const int MOD = 1e9 + 7;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.emplace_back(1);
        hFences.emplace_back(m);
        vFences.emplace_back(1);
        vFences.emplace_back(n);
        ranges::sort(hFences);
        ranges::sort(vFences);

        int ans = -1;
        set<int> s;
        for(int i = 0;i < hFences.size();i++) {
            for(int j = 0;j < i;j++) {
                s.insert(hFences[i] - hFences[j]);
            }
        }
        for(int i = 0;i < vFences.size();i++) {
            for(int j = 0;j < i;j++) {
                if(s.count(vFences[i] - vFences[j])) ans = max(ans, vFences[i] - vFences[j]);
            }
        }
        return ans == -1 ? -1 : 1ll * ans * ans % MOD;
    }
};
