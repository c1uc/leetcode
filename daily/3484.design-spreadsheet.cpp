#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Spreadsheet {
    public:
    vector<vector<int>> grid;
    using cell_idx = pair<int, int>;
        Spreadsheet(int rows) {
            grid = vector<vector<int>>(26, vector<int>(rows, 0));
        }

        cell_idx getCellIdx(string cell) {
            if(cell[0] >= 'A' && cell[0] <= 'Z') {
                return {cell[0] - 'A', stoi(cell.substr(1)) - 1};
            }
            return {-1, stoi(cell)};
        }

        int getCellValue(string cell) {
            cell_idx idx = getCellIdx(cell);
            if(idx.first == -1) {
                return idx.second;
            }
            return grid[idx.first][idx.second];
        }
        
        void setCell(string cell, int value) {
            cell_idx idx = getCellIdx(cell);
            grid[idx.first][idx.second] = value;
        }
        
        void resetCell(string cell) {
            cell_idx idx = getCellIdx(cell);
            grid[idx.first][idx.second] = 0;
        }
        
        int getValue(string formula) {
            string op1 = formula.substr(1, formula.find('+'));
            string op2 = formula.substr(formula.find('+') + 1);
            int val1 = getCellValue(op1);
            int val2 = getCellValue(op2);
            
            return val1 + val2;
        }
    };
    
    /**
     * Your Spreadsheet object will be instantiated and called as such:
     * Spreadsheet* obj = new Spreadsheet(rows);
     * obj->setCell(cell,value);
     * obj->resetCell(cell);
     * int param_3 = obj->getValue(formula);
     */
