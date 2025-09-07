#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll INF = 1e18;

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        auto log4 = [&](ll x) -> ll {
            return ll(log2(x) / log2(4));
        };

        auto sum_of_log4_before = [&](ll x) -> ll {
            ll sum = 0;
            ll cur = 4;
            while(cur <= x) {
                sum += (cur - (cur >> 2)) * log4(cur);
                cur <<= 2;
            }
            sum += (x - (cur >> 2) + 1) * log4(cur);
            return sum;
        };

        ll ans = 0;
        for(auto &q : queries) {
            ll op = sum_of_log4_before(q[1]) - sum_of_log4_before(q[0] - 1);
            ans += (op >> 1) + (op & 1);
        }
        return ans;
    }
};

