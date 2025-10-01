#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int numWaterBottles(int numBottles, int numExchange) {
            int ans = numBottles;
            while(numBottles >= numExchange) {
                ans += numBottles / numExchange;
                numBottles = numBottles % numExchange + numBottles / numExchange;
            }
            return ans;
        }
    };
