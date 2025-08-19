#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

auto OPS = vector<function<double(double, double)>>{
    [](double a, double b) { return a + b; },
    [](double a, double b) { return a - b; },
    [](double a, double b) { return b - a; },
    [](double a, double b) { return a * b; },
    [](double a, double b) { return a / b; },
    [](double a, double b) { return b / a; }
};


class Solution {
    public:
        bool judgePoint24(vector<int>& cards) {
            vector<double> nums(cards.begin(), cards.end());

            auto dfs = [&](this auto&& dfs) -> bool {
                if (nums.size() == 1) {
                    return abs(nums[0] - 24) < 1e-6;
                }
                for (int i = 0; i < nums.size(); i++) {
                    double a = nums[i];
                    for (int j = i + 1; j < nums.size(); j++) {
                        double b = nums[j];
                        nums.erase(nums.begin() + j);
                        for (int op = 0; op < OPS.size(); op++) {
                            if(op == 4 && abs(b) < 1e-6) continue;
                            if(op == 5 && abs(a) < 1e-6) continue;
                            nums[i] = OPS[op](a, b);
                            if (dfs()) return true;
                        }
                        nums.insert(nums.begin() + j, b);
                    }
                    nums[i] = a;
                }
                return false;
            };
            return dfs();
        }
    };
