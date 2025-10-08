#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
            vector<int> ans;
            sort(potions.begin(), potions.end());
            for(auto s: spells) {
                long long target = success / s + (success % s != 0);
                int d = lower_bound(potions.begin(), potions.end(), target) - potions.begin();
                ans.push_back(potions.size() - d);
            }
            return ans;
        }
    };

