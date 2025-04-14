#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll INF = 1e18;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> unique_xors;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                unique_xors.insert(nums[i] ^ nums[j]);
            }
        }
        unordered_set<int> unique_xors2;
        for(auto x : unique_xors) {
            for(int i = 0; i < n; i++) {
                unique_xors2.insert(x ^ nums[i]);
            }
        }
        return unique_xors2.size();
    }
};
