#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            int row[9][9] = {0}, col[9][9] = {0}, box[9][9] = {0};
            for(int r = 0; r < 9; r++) {
                for(int c = 0; c < 9; c++) {
                    if(board[r][c] == '.') continue;
                    int num = board[r][c] - '1';
                    int box_idx = (r / 3) * 3 + (c / 3);
                    if(row[r][num] || col[c][num] || box[box_idx][num]) return false;
                    row[r][num] = col[c][num] = box[box_idx][num] = 1;
                }
            }
            return true;
        }
    };
