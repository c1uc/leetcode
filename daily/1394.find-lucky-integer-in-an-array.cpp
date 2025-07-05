#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int c[501];

class Solution {
public:
    int findLucky(vector<int>& arr) {
        memset(c, 0, sizeof(c));
        for (int x : arr) {
            c[x]++;
        }
        for (int i = 500; i >= 1; i--) {
            if (c[i] == i) return i;
        }
        return -1;
    }
};
