#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<int> groups(n, 0);
        int group = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] - nums[i - 1] <= maxDiff) {
                groups[i] = group;
            } else {
                groups[i] = ++group;
            }
        }
        for(auto& q : queries) {
            if(groups[q[0]] == groups[q[1]]) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};
