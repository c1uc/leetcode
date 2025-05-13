#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        deque<int> dq(cnt.begin(), cnt.end());
        while(t--) {
            int z = dq.back();
            dq.pop_back();
            dq.front() += z;
            dq.front() %= MOD;
            dq.push_front(z);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += dq[i];
            ans %= MOD;
        }
        return ans;
    }
};
