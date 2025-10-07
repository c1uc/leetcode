template<typename T>
class ST {
    vector<vector<T>> st;
    function<T(T, T)> op;

public:
    ST(const vector<T>& a, function<T(T, T)> op = [](T a, T b) { return max(a, b); }) : op(op) {
        size_t n = a.size();
        int w = bit_width(n);
        st.resize(w, vector<T>(n));
        for (int j = 0; j < n; j++) {
            st[0][j] = a[j];
        }
        for (int i = 1; i < w; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    // [l, r)
    T query(int l, int r) const {
        int k = bit_width((uint32_t) r - l) - 1;
        return op(st[k][l], st[k][r - (1 << k)]);
    }
};