#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
            vector<vector<int>> res;
            ranges::sort(arr);
            int n = arr.size(), mn = INT_MAX;
            for(int i = 0;i < n - 1;i++) mn = min(mn, arr[i + 1] - arr[i]);
            for(int i = 0;i < n - 1;i++) if(arr[i + 1] - arr[i] == mn) res.emplace_back(vector<int>{arr[i], arr[i + 1]});
            return res;
        }
    };
