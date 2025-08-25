#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
            int n = mat.size(), m = mat[0].size();
            vector<int> ans;
            for(int k = 0;k < n + m - 1;k++) {
                if(k & 1) {
                    for(int i = max(0, k - m + 1);i < min(k + 1, n);i++) {
                        ans.push_back(mat[i][k - i]);
                    }
                }
                else {
                    for(int i = min(k, n - 1);i >= max(0, k - m + 1);i--) {
                        ans.emplace_back(mat[i][k - i]);
                    }
                }
            }
            return ans;
        }
    };
