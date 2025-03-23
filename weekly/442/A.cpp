#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll INF = 1e18;

class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        return min(n * n, maxWeight / w);
    }
};
