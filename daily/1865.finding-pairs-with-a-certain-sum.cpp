#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class FindSumPairs {
public:
    vector<int> v;
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v = nums2;
        for(int x : nums1) m1[x]++;
        for(int x : nums2) m2[x]++;
    }
    
    void add(int index, int val) {
        m2[v[index]]--;
        v[index] += val;
        m2[v[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto& [x, c] : m1) {
            if(m2.count(tot - x)) ans += c * m2[tot - x];
        }
        return ans;
    }
};
