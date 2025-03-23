/*
 * @lc app=leetcode id=2661 lang=cpp
 *
 * [2661] First Completely Painted Row or Column
 */

// @lc code=start
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll INF = 1e18;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int, pii> mp;
        for(int i = 0;i < mat.size();i++) {
            for(int j = 0;j < mat[i].size();j++) {
                mp[mat[i][j]] = {i, j};
            }
        }
        vector<int> row(mat.size(), mat[0].size()), col(mat[0].size(), mat.size());
        for(int i = 0;i < arr.size();i++) {
            auto [x, y] = mp[arr[i]];
            row[x]--;
            col[y]--;
            if(row[x] == 0 || col[y] == 0) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

