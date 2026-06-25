const int MOD = 1e9 + 7;

using vi = vector<long long>;
using vii = vector<vi>;

vii mulm(vii mat1, vii mat2) {
    int n = mat1.size(), k = mat2.size(), m = mat2[0].size();
    vii res(n, vi(m, 0));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            for(int w = 0;w < k;w++) res[i][j] = (1ll * mat1[i][w] * mat2[w][j] + res[i][j]) % MOD;
        }
    }
    return res;
}

vii fpow(vii mat, int n, vii v) {
    vii res = v;
    while(n) {
        if(n & 1) res = mulm(mat, res);
        mat = mulm(mat, mat);
        n >>= 1;
    }
    return res;
}


class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int w = r - l + 1;
        vii trans(w, vi(w));
        for(int i = 0;i < w;i++) {
            for(int j = 0;j < w - 1 - i;j++) trans[i][j] = 1;
        }
        vii vec(w, vi(1, 1));
        vii res = fpow(trans, n - 1, vec);
        long long ans = 0;
        for(auto& x: res) ans += x[0];
        return ans * 2 % MOD;
    }
};
