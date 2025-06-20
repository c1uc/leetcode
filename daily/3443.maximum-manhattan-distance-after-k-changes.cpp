#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0, x = 0, y = 0;
        for(int i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case 'N':
                    y++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'E':
                    x++;
                    break;
                case 'W':
                    x--;
                    break;
            }

            ans = max(ans, min(i + 1, 2 * k + abs(x) + abs(y)));
        }
        return ans;
    }
};
