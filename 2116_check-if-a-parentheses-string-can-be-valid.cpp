#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll INF = 1e18;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() & 1) return false;

        int locked_left = 0, locked_right = 0;
        int unlocked = 0;
        for(int i = 0;i < locked.size();i++) {
            if(locked[i] == '0') unlocked++;
            else if(s[i] == '(') locked_left++;
            else locked_right++;
        }

        int unlocked_left = (s.size() >> 1) - locked_left;
        int unlocked_right = (s.size() >> 1) - locked_right;

        if(unlocked_left < 0 || unlocked_right < 0) return false;

        int counter = 0;
        for(int i = 0;i < s.size();i++) {
            if(locked[i] == '1') {
                if(s[i] == '(') counter++;
                else counter--;
            } else {
                if(unlocked_left > 0) {
                    counter++;
                    unlocked_left--;
                } else {
                    counter--;
                    unlocked_right--;
                }
            }
            if(counter < 0) return false;
        }
        return counter == 0;
    }
};


signed main() {_
    string s = "(())";
    string locked = "1000";
    Solution solution;
    cout << solution.canBeValid(s, locked) << endl;
    return 0;
}
