#include <bits/stdc++.h>
using namespace std;

auto is_balanced = [](int x) -> bool {
    map<int, int> freq;
    while(x) {
        freq[x % 10]++;
        x /= 10;
    }
    return all_of(freq.begin(), freq.end(), [](auto x) { return x.second == x.first; });
};

set<int> balanced;
auto init = []() {
    for(int i = 1; i <= 2e6; i++) {
        if(is_balanced(i)) {
            balanced.insert(i);
        }
    }
    return 0;
}();


class Solution {
    public:
        int nextBeautifulNumber(int n) {
            return *balanced.lower_bound(n + 1);
        }
    };
