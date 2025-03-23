#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0, dir = 0;
        int ans = 0;
        vector dirs = vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<pair<int, int>> obs;
        for(auto& ob : obstacles) {
            obs.insert({ob[0], ob[1]});
        }
        for(auto c: commands) {
            if(c == -2) {
                dir = (dir + 3) % 4;
            } else if(c == -1) {
                dir = (dir + 1) % 4;
            } else {
                for(int i = 0;i < c;i++) {
                    int nx = x + dirs[dir].first;
                    int ny = y + dirs[dir].second;
                    if(obs.count({nx, ny})) {
                        break;
                    }
                    x = nx;
                    y = ny;
                }
                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }
};


signed main() {_

    return 0;
}
