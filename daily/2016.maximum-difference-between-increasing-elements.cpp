#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e9 + 10;


class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn = MAX, mx = 0, ans = 0;
        for(auto &x : nums) {
            if(x < mn) mn = mx = x;
            else mx = max(mx, x);
            ans = max(ans, mx - mn);
        }
        return ans == 0 ? -1 : ans;
    }
};
