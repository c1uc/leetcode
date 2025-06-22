#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> ans;
        numWays.insert(numWays.begin(), 0);
        vector<int> ways(numWays.size(), 0);
        ways[0] = 1;

        for(int i = 1; i < numWays.size(); i++) {
            if(!ways[i]) continue;
            if(ways[i] > numWays[i]) return {};
            if(ways[i] < numWays[i]) {
                ans.emplace_back(i);
                for(int j = i; j < numWays.size(); j++) {
                    ways[j] += ways[j - i];
                }
                if(ways[i] != numWays[i]) return {};
            }
        }

        return ans;
    }
};
