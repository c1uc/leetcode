const int MOD = 1e9 + 7;

int modpow(int x, int p) {
    int res = 1;
    while(p) {
        if(p & 1) res = 1ll * res * x % MOD;
        x = 1ll * x * x % MOD;
        p >>= 1;
    }
    return res;
}

int modinv(int x) {
    return modpow(x, MOD - 2);
}

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = (int)sqrt(n);
        auto diff = vector(B + 1, vector<int>(n, 1));
        for(auto& q: queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if(k <= B) {
                auto& df = diff[k];
                int rr = l + ((r - l) / k + 1) * k;
                df[l] = 1ll * df[l] * v % MOD;
                if(rr < n) {
                    df[rr] = 1ll * df[rr] * modinv(v) % MOD;
                }
            } else {
                while(l <= r) {
                    nums[l] = 1ll * nums[l] * v % MOD;
                    l += k;
                }
            }
        }
        for(int k = 1;k <= B;k++) {
            auto& df = diff[k];
            for(int i = 0;i < k;i++) {
                int idx = i, mul = 1;
                while(idx < n) {
                    mul = 1ll * mul * df[idx] % MOD;
                    nums[idx] = 1ll * nums[idx] * mul % MOD;
                    idx += k;
                }
            }
        }
        int res = 0;
        for(auto& x: nums) res ^= x;
        return res;
    }
};
