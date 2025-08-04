#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int minTime(string s, vector<int>& order, int k) {
            int n = s.size();
            if(k > n * (n - 1) / 2) {
                return -1;
            }
            vi star(n, 0);
            auto check = [&](int t) {
                for(int i = 0;i <= t;i++) {
                    star[order[i]] = t;
                }
                int last = 0;
                int cnt = n * (n - 1) / 2;
                for(int i = 0;i < n;i++) {
                    if(star[i] == t) {
                        last = i;
                    } else {
                        cnt -= i - last;
                    }
                }
                return cnt >= k;
            };
            int l = -1, r = n;
            while(l < r) {
                int mid = (l + r) >> 1;
                if(check(mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return r;
        }
    };
