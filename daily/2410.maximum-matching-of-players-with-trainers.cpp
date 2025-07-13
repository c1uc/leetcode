#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
            sort(players.begin(), players.end(), greater<int>());
            sort(trainers.begin(), trainers.end(), greater<int>());
            int ans = 0;
            for(int i = 0;i < players.size() && ans < trainers.size();i++) {
                if(players[i] <= trainers[ans]) {
                    ans++;
                }
            }
            return ans;
        }
    };
