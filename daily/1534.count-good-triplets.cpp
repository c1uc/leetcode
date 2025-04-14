#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int ans = 0;
        multiset<int> l, r;
        l.insert(arr[0]);
        for(int i = 1; i < n; i++) {
            r.insert(arr[i]);
        }
        for(int i = 1; i < n - 1; i++) {
            r.erase(r.find(arr[i]));
            auto l1 = l.lower_bound(arr[i] - a);
            auto l2 = l.upper_bound(arr[i] + a);
            auto r1 = r.lower_bound(arr[i] - b);
            auto r2 = r.upper_bound(arr[i] + b);

            vector<int> l_vec(l1, l2);
            vector<int> r_vec(r1, r2);

            int r_low = 0, r_high = 0;
            for(auto j = 0; j < l_vec.size(); j++) {
                while(r_low < r_vec.size() && r_vec[r_low] < l_vec[j] - c) {
                    r_low++;
                }
                while(r_high < r_vec.size() && r_vec[r_high] <= l_vec[j] + c) {
                    r_high++;
                }
                ans += r_high - r_low;
            }
            l.insert(arr[i]);
        }
        return ans;
    }
};
