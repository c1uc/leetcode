#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX_N = 10001;
vector<int> group(MAX_N, 0), ans(MAX_N, 0);
map<int, int> cnt;

auto init = []() {
    for (int i = 1; i < MAX_N; i++) {
        int x = i;
        while (x) {
            group[i] += x % 10;
            x /= 10;
        }
    }

    for(int i = 1; i < MAX_N; i++) {
        cnt[group[i]]++;
        int max_cnt = 0, max_group = 0;
        for(auto [k, v] : cnt) {
            if(v > max_cnt) {
                max_cnt = v;
                max_group = 1;
            } else if(v == max_cnt) {
                ++max_group;
            }
        }
        ans[i] = max_group;
    }
    return ans;
}();


class Solution {
public:
    int countLargestGroup(int n) {
        return ans[n];
    }
};
