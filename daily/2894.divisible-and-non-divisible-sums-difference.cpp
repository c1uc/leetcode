#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int differenceOfSums(int n, int m) {
        int tot = (1 + n) * n / 2;
        int div = (m + (n / m) * m) * (n / m) / 2;
        return tot - 2 * div;
    }
};
