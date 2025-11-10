#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minOperations(vector<int>& nums) {
            stack<int> s;
            int ans = 0;
            for(auto x: nums) {
                while(!s.empty() && s.top() > x) {
                    ans++;
                    s.pop();
                }
                if(!x) continue;
                if(s.empty() || s.top() < x) s.push(x);
            }
            return ans + s.size();
        }
    };