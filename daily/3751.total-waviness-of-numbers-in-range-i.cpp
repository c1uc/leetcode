class Solution {
public:
    int totalWaviness(int num1, int num2) {
        auto inc = [](int x, int y) -> int {
            return y > x ? 1 : (y < x ? -1 : 0);
        };
        auto wav = [](int flag, int x, int y) {
            if(flag == 1 && y < x) return 1;
            if(flag == -1 && y > x) return 1;
            return 0;
        };
        auto dfs = [&](this auto&& dfs, int i, string s, bool is_limit, bool is_num, int prev, int flag, int c) -> int {
            if(i == s.size()) return c;
            int res = 0;

            if(!is_num) res += dfs(i + 1, s, false, false, -1, 0, 0);

            int low = is_num ? 0 : 1;
            int high = is_limit ? s[i] - '0' : 9;

            for(int d = low; d <= high; d++) {
                res += dfs(i + 1, s, is_limit && d == high, true, d, prev == -1 ? 0 : inc(prev, d), c + wav(flag, prev, d));
            }
            return res;
        };
        return dfs(0, to_string(num2), true, false, -1, 0, 0) - dfs(0, to_string(num1 - 1), true, false, -1, 0, 0);
    }
};
