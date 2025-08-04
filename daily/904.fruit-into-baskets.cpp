#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int n = fruits.size();
            vi cnt(n);
            int ans = 0, c = 0;
            for(int l = 0, r = 0;r < n;r++) {
                if(cnt[fruits[r]] == 0) {
                    c++;
                }
                cnt[fruits[r]]++;
                while(c > 2) {
                    cnt[fruits[l]]--;
                    if(cnt[fruits[l]] == 0) {
                        c--;
                    }
                    l++;
                }
                ans = max(ans, r - l + 1);
            }
            return ans;
        }
    };
