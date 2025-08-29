#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        long long flowerGame(int n, int m) {
            return static_cast<ll>(((n + 1) >> 1)) * static_cast<ll>(m >> 1) + static_cast<ll>((n >> 1)) * static_cast<ll>(((m + 1) >> 1));
        }
    };
