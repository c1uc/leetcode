#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e5 + 5;

vector<int> v = {0, 1, 2, 3, 4};

class Solution {
public:
    int maxDifference(string s, int k) {
        int ans = -MAX;
        for(auto x: v) {
            for(auto y: v) {
                if(x == y) continue;
                int sum_l[5] = {0}, sum_r[5] = {0};
                int min_diff[4] = {MAX, MAX, MAX, MAX};
                int l = 0;
                for(int i = 0;i < s.length();i++) {
                    sum_r[s[i] - '0']++;
                    int r = i + 1;
                    while(r - l >= k && sum_r[x] > sum_l[x] && sum_r[y] > sum_l[y]) {
                        int p = 1 - (sum_l[x] & 1), q = sum_l[y] & 1;
                        min_diff[p * 2 + q] = min(min_diff[p * 2 + q], sum_l[x] - sum_l[y]);
                        sum_l[s[l] - '0']++;
                        l++;
                    }
                    if(r >= k) {
                        ans = max(ans, sum_r[x] - sum_r[y] - min_diff[2 * (sum_r[x] & 1) + (sum_r[y] & 1)]);
                    }
                }
            }
        }
        return ans;
    }
};
