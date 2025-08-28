#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            cost.emplace_back(0);
            for(int i = 2; i <= n; i++) {
                cost[i] += min(cost[i - 1], cost[i - 2]);
            }
            return cost[n];
        }
    };
