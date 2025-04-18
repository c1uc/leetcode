#include <bits/stdc++.h>
using namespace std;

vector<string> s(31);
auto init = []() {
    s[1] = "1";
    for (int i = 2; i <= 30; i++) {
        string t = s[i - 1];
        s[i] = "";
        int cnt = 1;
        for (int j = 0; j < t.size(); j++) {
            if (j + 1 < t.size() && t[j] == t[j + 1]) {
                cnt++;
            } else {
                s[i] += to_string(cnt) + t[j];
                cnt = 1;
            }
        }
    }
    return 0;
}();

class Solution {
public:
    string countAndSay(int n) {
        return s[n];
    }
};