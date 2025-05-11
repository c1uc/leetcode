#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int c = 0;
        for(auto x : arr) {
            if(x & 1) {
                c++;
            } else {
                c = 0;
            }
            if(c >= 3) {
                return true;
            }
        }
        return false;
    }
};
