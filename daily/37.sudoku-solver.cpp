#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        void solveSudoku(vector<vector<char>>& board) {
            int row[9][9] = {0}, col[9][9] = {0}, box[9][9] = {0};
            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 9; j++) {
                    if(board[i][j] != '.') {
                        int b = i / 3 * 3 + j / 3;
                        row[i][board[i][j] - '1'] = 1;
                        col[j][board[i][j] - '1'] = 1;
                        box[b][board[i][j] - '1'] = 1;
                    }
                }
            }
            
            auto dfs = [&](this auto&& dfs, int r, int c) -> bool {
                if(r == 9) return true;
                if(c == 9) return dfs(r + 1, 0);
                if(board[r][c] != '.') return dfs(r, c + 1);
                int b = r / 3 * 3 + c / 3;
                for(int i = 1; i <= 9; i++) {
                    if(row[r][i - 1] || col[c][i - 1] || box[b][i - 1]) continue;
                    board[r][c] = '0' + i;
                    row[r][i - 1] = col[c][i - 1] = box[b][i - 1] = 1;
                    if(dfs(r, c + 1)) return true;
                    board[r][c] = '.';
                    row[r][i - 1] = col[c][i - 1] = box[b][i - 1] = 0;
                }
                return false;
            };
            dfs(0, 0);
            return;
        }
    };
