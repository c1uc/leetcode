#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll sum1 = accumulate(nums1.begin(), nums1.end(), 0ll), sum2 = accumulate(nums2.begin(), nums2.end(), 0ll);
        int cnt1 = count(nums1.begin(), nums1.end(), 0), cnt2 = count(nums2.begin(), nums2.end(), 0);
        if (cnt1 == 0 && cnt2 == 0) return sum1 == sum2 ? sum1 : -1;
        if (cnt1 == 0) return sum2 + cnt2 <= sum1 ? sum1 : -1;
        if (cnt2 == 0) return sum1 + cnt1 <= sum2 ? sum2 : -1;
        return max(sum1 + cnt1, sum2 + cnt2);
    }
};
