#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        vector<int> sumZero(int n) {
            vector<int> ans(n, 0);
            for(int i = 0;i < (n >> 1);i++) {
                ans[i] = i + 1;
                ans[n - i - 1] = -(i + 1);
            }
            return ans;
        }
    };
