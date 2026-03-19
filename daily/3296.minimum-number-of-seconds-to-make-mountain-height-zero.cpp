class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto chk = [&](long long x) -> bool {
            long long h = mountainHeight;
            for(auto c : workerTimes) {
                h -= (long long)((sqrt(8ll * x / c + 1) - 1) / 2);
            }
            return h <= 0;
        };
        long long l = 0, r = 1ll << 60;
        while(l + 1 < r) {
            long long mid = (l + r) >> 1;
            if(chk(mid)) r = mid;
            else l = mid;
        }
        return r;
    }
};
