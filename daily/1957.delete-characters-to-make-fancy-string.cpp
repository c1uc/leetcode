#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        string makeFancyString(string s) {
            string ans;
            for(auto c: s) {
                if(ans.size() >= 2 && ans.back() == c && ans[ans.size() - 2] == c) {
                    continue;
                }
                ans += c;
            }
            return ans;
        }
    };
