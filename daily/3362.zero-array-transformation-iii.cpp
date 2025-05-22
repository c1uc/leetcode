#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        sort(queries.begin(), queries.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        
        priority_queue<int> pq;
        int idx = 0, ops = 0;
        vector<int> diff(n + 1, 0);
        for(int i = 0; i < n; i++) {
            ops += diff[i];
            while(idx < queries.size() && queries[idx][0] == i) {
                pq.push(queries[idx][1]);
                idx++;
            }
            while(ops < nums[i] && !pq.empty() && pq.top() >= i) {
                ops++;
                diff[pq.top() + 1]--;
                pq.pop();
            }
            if(ops < nums[i]) {
                return -1;
            }
        }
        return pq.size();
    }
};
