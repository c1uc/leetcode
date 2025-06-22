#include <bits/stdc++.h>
using namespace std;
typedef tuple<double, int, int> ti;

const double INF = 1e18;

class Solution {
public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        vector<vector<double>> dp(1 << n, vector<double>(m, INF));
        priority_queue<ti, vector<ti>, greater<ti>> pq;
        pq.emplace(0, 0, 0);

        double ans = INF;

        while(!pq.empty()) {
            auto [t, mask, stage] = pq.top();
            pq.pop();
            if(t > dp[mask][stage]) continue;
            
            vector<int> remaining;
            for(int x = 0; x < n; x++) {
                if(mask & (1 << x)) continue;
                remaining.emplace_back(x);
            }

            int transport_sz = min(k, (int)remaining.size());
            for(int sz = 1; sz <= transport_sz; sz++) {
                vector<bool> selected(remaining.size(), false);
                for(int x = 0; x < sz; x++) {
                    selected[x] = true;
                }
                do {
                    double nt = 0;
                    int n_mask = mask;
                    for(int x = 0; x < n; x++) {
                        if(!selected[x]) continue;
                        nt = max(nt, (double)time[remaining[x]]);
                        n_mask |= (1 << remaining[x]);
                    }
                    nt *= mul[stage];
                    int n_stage = (stage + int(nt) % m) % m;
                    nt += t;

                    if(n_mask == (1 << n) - 1) ans = min(ans, nt);
                    else {
                        for(int x = 0; x < n; x++) {
                            if(!(n_mask & (1 << x))) continue;
                            double return_time = time[x] * mul[n_stage];
                            int return_stage = (n_stage + int(return_time) % m) % m;
                            int return_mask = n_mask & ~(1 << x);
                            return_time += nt;
                            
                            if(return_time < dp[return_mask][return_stage]) {
                                dp[return_mask][return_stage] = return_time;
                                pq.emplace(return_time, return_mask, return_stage);
                            }
                        }
                    }
                } while(prev_permutation(selected.begin(), selected.end()));
            }
        }
        if(ans == INF) return -1;
        return ans;
    }
};
