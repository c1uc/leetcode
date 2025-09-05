#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int makeTheIntegerZero(int num1, int num2) {
            for(int i = 1;i < 32;i++) {
                int k = num1 - i * num2;
                if(k >= i && k <= __builtin_popcount(k)) return i;
            }
            return -1;
        }
    };
