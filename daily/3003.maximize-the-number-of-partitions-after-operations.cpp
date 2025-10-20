class Solution {
    public:
        int maxPartitionsAfterOperations(string s, int k) {
            if(k == 26) return 1;
    
            int n = s.size();
            auto convert = [](int idx, uint32_t mask, int changed) -> long long {
                return (long long) idx << 32 | mask << 1 | changed;
            };
    
            unordered_map<long long, int> memo;
            auto dp = [&](this auto&& dp, int idx, uint32_t mask, int changed) -> int {
                if(idx == n) return 1;
    
                long long v = convert(idx, mask, changed);
                auto it = memo.find(v);
                if(it != memo.end()) return it->second;
    
                int res = 0;
    
                uint32_t bit = 1 << (s[idx] - 'a');
                uint32_t new_mask = mask | bit;
                if(popcount(new_mask) > k) {
                    res = dp(idx + 1, bit, changed) + 1;
                } else {
                    res = dp(idx + 1, new_mask, changed);
                }
    
                if(changed) return memo[v] = res;
    
                for(int c = 0;c < 26;c++) {
                    uint32_t bit = 1 << c;
                    uint32_t new_mask = mask | bit;
                    if(popcount(new_mask) > k) {
                        res = max(res, dp(idx + 1, bit, 1) + 1);
                    } else {
                        res = max(res, dp(idx + 1, new_mask, 1));
                    }
                }
                return memo[v] = res;
            };
            return dp(0, 0, 0);
        }
    };