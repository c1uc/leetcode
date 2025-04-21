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
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long long high = 0, low = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            sum += differences[i];
            high = max(high, sum);
            low = min(low, sum);
        }
        return max(0, (int)((upper - high) - (lower - low) + 1));
    }
};