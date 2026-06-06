using ll = long long;

class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        vector<array<array<pair<ll, ll>, 10>, 3>> dp(16);
        auto solve = [&]() {
            string s1 = to_string(num1);
            string s2 = to_string(num2);
            int n = s2.size();
            int ofs = n - s1.size();
            auto dfs = [&](this auto&& dfs, int i, bool limit_high, bool limit_low, int last_cmp, int last_dig) -> pair<ll, ll> {
                if(i == n) return {0, 1};
                auto& rec = dp[i][last_cmp + 1][last_dig];
                if(!limit_high && !limit_low && rec.second) return rec;

                long long wav = 0, cnt = 0;
                int lo = limit_low && i >= ofs ? s1[i - ofs] - '0' : 0;
                int hi = limit_high ? s2[i] - '0' : 9;

                bool is_num = !limit_low || i > ofs;
                for(int d = lo; d <= hi;d++) {
                    int cmp = !is_num ? 0 : (d > last_dig) - (d < last_dig);
                    auto [sub_w, sub_c] = dfs(i + 1, limit_high && d == hi, limit_low && d == lo, cmp, d);
                    if(cmp * last_cmp == -1) wav += sub_c;
                    cnt += sub_c;
                    wav += sub_w;
                }

                pair<ll, ll> res = {wav, cnt};
                if(!limit_low && !limit_high) rec = res;
                return res;
            };
            return dfs(0, true, true, 0, 0).first;
        };
        return solve();
    }
};
