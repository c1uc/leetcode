#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long maxPower(vector<int>& stations, int radius, int k) {
            int n = stations.size();
            vector<long long> diff(n + 1, 0);
            for(int i = 0;i < n;i++) {
                diff[max(0, i - radius)] += stations[i];
                diff[min(n, i + radius + 1)] -= stations[i];
            }
            auto check = [&](long long x) -> bool {
                auto new_df = diff;
                int rem = k;
                long long sum = 0;
                for(int i = 0;i < n;i++) {
                    sum += new_df[i];
                    if(sum < x) {
                        long long need = x - sum;
                        if(need > rem) return false;
                        rem -= need;
                        new_df[i] += need;
                        sum += need;
                        new_df[min(n, i + 2 * radius + 1)] -= need;
                    }
                }
                return true;
            };
            long long l = 0, r = 1e18;
            while(l + 1 < r) {
                long long mid = (l + r) >> 1;
                if(check(mid)) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            return l;
        }
    };
