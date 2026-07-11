const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 1;
int pow10[MAXN];

int init = [] {
    pow10[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pow10[i] = pow10[i - 1] * 10ll % MOD;
    }
    return 'c';
}();

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> pre(n + 1, 0), rec(n + 1, 0), idx(n + 1, 0);
        for(auto [i, c]: s | views::enumerate) {
            pre[i + 1] = pre[i] + (c - '0');
            rec[i + 1] = c > '0' ? (rec[i] * 10 + c - '0') % MOD : rec[i];
            idx[i + 1] = idx[i] + (c > '0');
        }
        auto qu = [&](int l, int r) -> int {
            int li = idx[l], ri = idx[r];
            int len = ri - li;
            long long sum = pre[r] - pre[l], c = (rec[r] - 1ll * rec[l] * pow10[len]) % MOD;
            return 1ll * (c + MOD) * sum % MOD;
        };
        return queries | views::transform([&](const auto& q) { return qu(q[0], q[1] + 1); }) | ranges::to<vector<int>>();
    }
};
