#include <bits/stdc++.h>

#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

class Solution {
 public:
  int maxDiff(int num) {
    string s = to_string(num);
    auto first_not_nine = ranges::find_if(s, [&](char c) { return c != '9'; });
    first_not_nine = first_not_nine != s.end() ? first_not_nine : s.begin();
    auto first_not_one =
        ranges::find_if(s, [&](char c) { return c != '1' && c != '0'; });
    first_not_one = first_not_one != s.end() ? first_not_one : s.begin();
    return stoi(s | views::transform([&](char c) {
                  return c == *first_not_nine ? '9' : c;
                }) |
                ranges::to<string>()) -
           stoi(s | views::transform([&](char c) {
                  return c == *first_not_one
                             ? (first_not_one != s.begin() ? '0' : '1')
                             : c;
                }) |
                ranges::to<string>());
  }
};
