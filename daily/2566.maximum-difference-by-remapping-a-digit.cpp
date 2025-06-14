#include <bits/stdc++.h>

#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

class Solution {
 public:
  int minMaxDifference(int num) {
    string s = to_string(num);
    auto first_not_nine = ranges::find_if(s, [&](char c) { return c != '9'; });
    auto first_not_zero = ranges::find_if(s, [&](char c) { return c != '0'; });
    string s1 = (first_not_nine != s.end())
                    ? s | views::transform([&](char c) {
                        return c == *first_not_nine ? '9' : c;
                      }) | ranges::to<string>()
                    : s;
    string s2 = (first_not_zero != s.end())
                    ? s | views::transform([&](char c) {
                        return c == *first_not_zero ? '0' : c;
                      }) | ranges::to<string>()
                    : s;
    return stoi(s1) - stoi(s2);
  }
};
