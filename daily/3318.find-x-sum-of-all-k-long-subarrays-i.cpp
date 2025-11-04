#include <bits/stdc++.h>
using namespace std;


class Solution {
    using pii = pair<int, int>;
    public:
        vector<int> findXSum(vector<int>& nums, int k, int x) {
            int n = nums.size();
            array<int, 51> freq = {0};
            set<pii> l, r;
            int l_sum = 0;
            vector<int> ans(n - k + 1);
            auto insert = [&](int x) {
                if(!freq[x]) return;
                auto p = pii{freq[x], x};
                if(!l.empty() && p > *l.begin()) {
                    l_sum += freq[x] * x;
                    l.insert(p);
                }
                else r.insert(p);
            };
            auto remove = [&](int x) {
                if(!freq[x]) return;
                auto p = pii{freq[x], x};
                if(l.count(p)) {
                    l_sum -= freq[x] * x;
                    l.erase(p);
                }
                else r.erase(p);
            };
            auto balance = [&]() {
                while(l.size() < x && !r.empty()) {
                    auto p = *r.rbegin();
                    l_sum += p.first * p.second;
                    l.insert(p);
                    r.erase(p);
                }
                while(l.size() > x && !l.empty()) {
                    auto p = *l.begin();
                    l_sum -= p.first * p.second;
                    r.insert(p);
                    l.erase(p);
                }
            };
            for(int i = 0;i < n;i++) {
                int in = nums[i];
                remove(in);
                freq[in]++;
                insert(in);

                int ll = i - k + 1;
                if(ll < 0) continue;

                balance();
                ans[ll] = l_sum;

                int out = nums[ll];
                remove(out);
                freq[out]--;
                insert(out);
            }
            return ans;
        }
    };
