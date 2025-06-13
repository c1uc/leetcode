#include <bits/stdc++.h>

#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

class Solution {
 public:
  int minimizeMax(vector<int> &nums, int p) {
    if (p == 0) return 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    auto diff = views::iota(0, n - 1) | views::transform([&](int i) {
                  return abs(nums[i] - nums[i + 1]);
                });
    int mn = ranges::min(diff);
    int mx = ranges::max(diff);
    if (p == 1) return mn;
    if (p << 1 == n)
      return ranges::max(views::iota(0, n >> 1) | views::transform([&](int i) {
                           return abs(nums[i << 1] - nums[(i << 1) | 1]);
                         }));
    int lo = mn - 1, hi = mx;

    auto chk = [&](int x) {
      int cnt = 0;
      for (int i = 0; i < n - 1; i++) {
        if (diff[i] <= x) {
          cnt++;
          i++;
        }
      }
      return cnt >= p;
    };

    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      if (chk(mid)) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    return hi;
  }
};
