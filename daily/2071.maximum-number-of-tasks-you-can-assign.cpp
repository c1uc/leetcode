#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int n = tasks.size();
        int m = workers.size();

        auto valid = [&](int mid){
            if(mid > m) return false;

            multiset<int> workers_set(workers.rbegin(), workers.rbegin() + mid);
            int pil = 0;

            for(int i = mid - 1; i >= 0; i--) {
                auto it = prev(workers_set.end());
                if(*it < tasks[i]) {
                    if(pil == pills) return false;
                    pil++;
                    it = workers_set.lower_bound(tasks[i] - strength);
                    if(it == workers_set.end()) return false;
                }
                workers_set.erase(it);
            }
            return true;
        };

        int l = 0, r = min(n, m) + 1;
        while(l + 1 < r){
            int mid = (l + r) / 2;
            cout << mid << endl;
            if(valid(mid)){
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
