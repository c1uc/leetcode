#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
            int s = accumulate(apple.begin(), apple.end(), 0), ans = 0;
            sort(capacity.begin(), capacity.end(), greater<int>());
            for(auto c: capacity) {
                ans++;
                s -= c;
                if(s <= 0) break;
            }
            return ans;
        }
    };
