#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MAX = 1e10 + 1;


class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        auto chk = [&](ll x) {
            ll cnt = 0;
            for (auto& num : nums1) {
                if(num == 0) {
                    if(x >= 0) cnt += nums2.size();
                } else {
                    ll tar = x / num;
                    if(x < 0 && tar * num != x) {
                        tar += (num > 0 ? -1 : 1);
                    }
                    if(num > 0) {
                        cnt += upper_bound(nums2.begin(), nums2.end(), tar) - nums2.begin();
                    } else {
                        cnt += nums2.size() - (lower_bound(nums2.begin(), nums2.end(), tar) - nums2.begin());
                    }
                }
            }
            return cnt;
        };

        ll l = -MAX, r = MAX;
        while (l + 1 < r) {
            ll mid = (l + r) >> 1;
            if (chk(mid) < k) l = mid;
            else r = mid;
        }
        return r;
    }
};