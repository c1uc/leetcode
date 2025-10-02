#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int maxBottlesDrunk(int numBottles, int numExchange) {
            int b = 2 * numExchange - 3;
            int c = -2 * numBottles;
            int d = b * b - 4 * c;
            double x = ceil((-b + sqrt((double)d)) / 2);
            return (int)x + numBottles - 1;
        }
    };
