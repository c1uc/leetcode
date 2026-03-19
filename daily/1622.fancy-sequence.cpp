class Fancy {
    long long offset = 0;
    long long ratio = 1;
    const long long MOD = 1e9 + 7;

    long long modpow(long long a, long long b) {
        long long res = 1;
        while(b) {
            if(b & 1) res = a * res % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    vector<long long> vals;
public:
    void append(int val) {
        vals.push_back(((val - offset + MOD) % MOD) * modpow(ratio, MOD - 2) % MOD);
    }
    
    void addAll(int inc) {
        offset += inc;
    }
    
    void multAll(int m) {
        offset = offset * m % MOD;
        ratio = ratio * m % MOD;
    }
    
    int getIndex(int idx) {
        if(idx >= vals.size()) return -1;
        return (vals[idx] * ratio + offset) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
