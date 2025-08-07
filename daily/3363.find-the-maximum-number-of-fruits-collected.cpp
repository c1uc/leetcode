#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int maxCollectedFruits(vector<vector<int>>& fruits) {
            int n = fruits.size();
            int diag = 0;
            for(int i = 0;i < n;i++) {
                diag += fruits[i][i];
                fruits[i][i] = 0;
            }
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < n;j++) {
                    if(i + j < n - 1) fruits[i][j] = 0;
                    else break;
                }
            }

            for(int i = 1;i < n - 1;i++) {
                for(int j = n - 1;j >= max({i + 1, n - i - 1});j--) {
                    fruits[i][j] += max({fruits[i - 1][j - 1], fruits[i - 1][j], ((j + 1 < n) ? fruits[i - 1][j + 1] : 0)});
                    fruits[j][i] += max({fruits[j - 1][i - 1], fruits[j][i - 1], ((j + 1 < n) ? fruits[j + 1][i - 1] : 0)});
                }
            }
            return diag + fruits[n - 2][n - 1] + fruits[n - 1][n - 2];
        }
    };
