#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int evenNumberBitwiseORs(vector<int>& nums) {
            int ans = 0;
            for(auto x: nums) {
                if(x % 2 == 0) {
                    ans |= x;
                }
            }
            return ans;
        }
    }; 

// ©leetcode
