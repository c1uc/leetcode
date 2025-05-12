#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> cnt(10);
        for(auto x : digits) {
            cnt[x]++;
        }
        vector<int> ans;
        for(int i = 1; i <= 9; i++) {
            if(cnt[i] == 0) continue;
            cnt[i]--;
            for(int j = 0; j <= 9; j++) {
                if(cnt[j] == 0) continue;
                cnt[j]--;
                for(int k = 0; k <= 9; k++) {
                    if(cnt[k] == 0) continue;
                    if(k % 2 == 0) {
                        ans.emplace_back(i * 100 + j * 10 + k);
                    }
                }
                cnt[j]++;
            }
            cnt[i]++;
        }
        return ans;
    }
};
