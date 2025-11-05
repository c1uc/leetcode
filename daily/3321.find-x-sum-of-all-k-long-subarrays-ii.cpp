#include <bits/stdc++.h>
using namespace std;


class Solution {
    using pii = pair<int, int>;
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        long long sum = 0;
        int n = nums.size();
        unordered_map<int, int> freq;
        set<pii> top, down;
        auto add = [&](int num) {
            pii p = {freq[num], num};
            if(p.first == 0) return;
            if(!top.empty() && p > *top.begin()) {
                top.insert(p);
                sum += (long long)p.second * p.first;
            }
            else down.insert(p);
        };
        auto del = [&](int num) {
            pii p = {freq[num], num};
            if(p.first == 0) return;
            if(top.find(p) != top.end()) {
                top.erase(p);
                sum -= (long long)p.second * p.first;
            } else down.erase(p);
        };
        auto balance = [&]() {
            while(top.size() < x && !down.empty()) {
                auto p = *down.rbegin();
                down.erase(p);
                top.insert(p);
                sum += (long long)p.second * p.first;
            }
            while(top.size() > x) {
                auto p = *top.begin();
                top.erase(p);
                down.insert(p);
                sum -= (long long)p.second * p.first;
            }
        };
        vector<long long> ans(n - k + 1);
        for(int i = 0;i < n;i++) {
            int a = nums[i];
            del(a);
            freq[a]++;
            add(a);

            int idx = i - k + 1;
            if(idx < 0) continue;
            balance();
            ans[idx] = sum;

            int b = nums[idx];
            del(b);
            freq[b]--;
            add(b);
        }
        return ans;
    }
};