#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int df[100002];

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        memset(df, 0, sizeof(df));
        for (auto& q : queries) {
            df[q[0]]++;
            df[q[1] + 1]--;
        }
        
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += df[i];
            if (sum < nums[i]) {
                return false;
            }
        }
        return true;
    }
};
