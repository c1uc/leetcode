#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n > m) {
            swap(nums1, nums2);
            swap(n, m);
        }
        int l = 0, r = n;
        while (l <= r) {
            int i = (l + r) / 2;
            int j = (n + m + 1) / 2 - i;
            if (i < n && nums1[i] < nums2[j - 1]) {
                l = i + 1;
            } else if (i > 0 && nums1[i - 1] > nums2[j]) {
                r = i - 1;
            } else {
                int l1 = i == 0 ? INT_MIN : nums1[i - 1];
                int l2 = j == 0 ? INT_MIN : nums2[j - 1];
                int r1 = i == n ? INT_MAX : nums1[i];
                int r2 = j == m ? INT_MAX : nums2[j];
                if ((n + m) % 2 == 1) {
                    return max(l1, l2);
                } else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }
        }
        return 0;
    }
};

signed main() {
    _

    return 0;
}
