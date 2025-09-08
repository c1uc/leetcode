#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        vector<int> getNoZeroIntegers(int n) {
            for(int i = 1; i < n; i++) {
                if(to_string(i).find('0') == string::npos && to_string(n - i).find('0') == string::npos) {
                    return {i, n - i};
                }
            }
            return {0, 0};
        }
    };
