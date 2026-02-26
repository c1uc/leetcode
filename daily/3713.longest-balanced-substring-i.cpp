class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0, n = s.size();
        for(int l = 0;l < n;l++) {
            array<int, 26> c = {0};
            for(int r = l;r < n;r++) {
                int tar = ++c[s[r] - 'a'];
                bool flag = true;
                for(int i = 0;i < 26 && flag;i++) if(c[i] && c[i] != tar) flag = false;
                if(flag) ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};
