class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        auto chk1 = [&]() -> int {
            int mx = 1;
            for(auto i = 1, l = 1; i < n;i++) {
                if(s[i] == s[i - 1]) {
                    mx = max(++l, mx);
                } else {
                    l = 1;
                }
            }
            return mx;
        };
        auto chk2 = [&](const string tar) -> int {
            unordered_map<int, int> mp;
            mp[0] = -1;
            auto a = tar[0], b = tar[1], other = tar[2];
            int cnt = 0, mx = 0;
            for(int i = 0;i < n;i++) {
                auto c = s[i];
                if(c == other) {
                    mp.clear();
                    cnt = 0;
                    mp[0] = i;
                } else {
                    cnt += (c == a);
                    cnt -= (c == b);
                    if(mp.count(cnt)) {
                        mx = max(mx, i - mp[cnt]);
                    } else {
                        mp[cnt] = i;
                    }
                }
            }
            return mx;
        };
        auto chk3 = [&]() -> int {
            unordered_map<string, int> mp;
            mp["0/0/"] = -1;
            int cnt[3] = {0}, mx = 0;
            for(int i = 0;i < n;i++) {
                auto c = s[i];
                cnt[c - 'a']++;
                if(c - 'a') cnt[c - 'a' - 1]--;
                string k = "";
                for(int i = 0;i < 2;i++) k += to_string(cnt[i]) + "/";
                if(mp.count(k)) {
                    mx = max(mx, i - mp[k]);
                } else mp[k] = i;
            }
            return mx;
        };
        return max({chk1(), chk2("abc"), chk2("cab"), chk2("bca"), chk3()});
    }
};
