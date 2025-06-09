#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int findKthNumber(int n, int k) {
        auto prefix = [&](long long x) {
            long long y = x + 1;
            int ans = 0;
            while(x <= n) {
                ans += min((long long)n + 1, y) - x;
                x *= 10;
                y *= 10;
            }
            return ans;
        };
        long long x = 1;
        while(k > 1) {
            int cnt = prefix(x);
            if(cnt < k) {
                k -= cnt;
                x++;
            } else {
                k--;
                x *= 10;
            }
        }
        return x;
    }
};
