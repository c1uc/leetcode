#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int countSquares(vector<vector<int>>& matrix) {
            int n = matrix.size(), m = matrix[0].size();
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(matrix[i][j] == 0) continue;
                    if(i == 0 || j == 0) matrix[i][j] = 1;
                    else matrix[i][j] = min(matrix[i - 1][j], min(matrix[i][j - 1], matrix[i - 1][j - 1])) + 1;
                }
            }
            return ranges::fold_left_first(matrix | views::join | views::all, plus<>());
        }
    };
