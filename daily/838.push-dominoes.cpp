#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> force(n, 0);
        int f = 0;
        for(int i = 0; i < n; i++) {
            if(dominoes[i] == 'R') {
                f = n;
            }
            else if(dominoes[i] == 'L') {
                f = 0;
            }
            else {
                f = max(f - 1, 0);
            }
            force[i] += f;
        }
        for(int i = n - 1; i >= 0; i--) {
            if(dominoes[i] == 'L') {
                f = -n;
            }
            else if(dominoes[i] == 'R') {
                f = 0;
            }
            else {
                f = min(f + 1, 0);
            }
            force[i] += f;
        }
        string res = "";
        for(int i = 0; i < n; i++) {
            if(force[i] > 0) {
                res += 'R';
            }
            else if(force[i] < 0) {
                res += 'L';
            }
            else {
                res += '.';
            }
        }
        return res;
    }
};