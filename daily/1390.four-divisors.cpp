#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100003;

vector<int> res(MAXN, -1);

auto init = []() -> int {
    vector<int> is_prime(MAXN, 1);
    is_prime[0] = 0;
    is_prime[1] = 0;
    for(int i = 2;i < MAXN;i++) {
        if(!is_prime[i]) continue;
        for(long long j = 1ll * i * i;j < MAXN;j += i) is_prime[j] = 0;
    }
    vector<long long> p;
    for(int i = 0;i < MAXN;i++) if(is_prime[i]) p.emplace_back(i);
    for(int i = 0;i < p.size();i++) {
        for(int j = i + 1;j < p.size();j++) {
            if(p[i] * p[j] < MAXN) res[p[i] * p[j]] = 1 + p[i] * p[j] + p[i] + p[j];
        }
        if(p[i] * p[i] * p[i] < MAXN) res[p[i] * p[i] * p[i]] = 1 + p[i] + p[i] * p[i] + p[i] * p[i] * p[i];
    }
    return 1;
}();

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto x: nums) {
            if(res[x] != -1) ans += res[x];
        }
        return ans;
    }
};
