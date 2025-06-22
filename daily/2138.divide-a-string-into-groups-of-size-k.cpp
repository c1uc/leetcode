#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for(int i = 0; i < s.size(); i += k) {
            string t = s.substr(i, k);
            if(t.size() < k) t += string(k - t.size(), fill);
            ans.emplace_back(t);
        }
        return ans;
    }
};
