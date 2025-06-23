#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


vector<vector<ll>> ans(10, vector<ll>(31, 0));

auto is_palindrome = [](string s) {
    int n = s.size();
    for (int i = 0; i < n >> 1; i++) {
        if (s[i] != s[n - i - 1]) return false;
    }
    return true;
};

auto convert_base_10_to_k = [](string s0, int k) {
    long long n = stoll(s0);
    string s;
    while (n) {
        s += '0' + (n % k);
        n /= k;
    }
    reverse(s.begin(), s.end());
    return s;
};

auto init = []() {
    for (int k = 2; k <= 9; k++) {
        int l = 1, n = 0;
        while(n < 30) {
            int r = l * 10;
            for(int op = 0; op < 2 && n < 30; op++) {
                for(int i = l; i < r && n < 30; i++) {
                    string ll = to_string(i);
                    string rr = to_string(op == 0 ? i / 10 : i);
                    if(rr == "0") rr = "";
                    reverse(rr.begin(), rr.end());
                    string s = ll + rr;
                    string s1 = convert_base_10_to_k(s, k);
                    if(is_palindrome(s1)) {
                        ans[k][n] = stoll(s);
                        n++;
                    }
                }
            }
            l *= 10;
        }
        for(int i = 1; i < 30; i++) {
            ans[k][i] += ans[k][i - 1];
        }
    }
    return 0;
}();


class Solution {
public:
    long long kMirror(int k, int n) {
        return ans[k][n - 1];
    }
};
