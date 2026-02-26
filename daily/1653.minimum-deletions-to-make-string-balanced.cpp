class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), c = 0;
        int ans = n;
        vector<int> suf(n, 0);
        for(int i = n - 2;i >= 0;i--) {
            suf[i] = suf[i + 1] + (s[i + 1] == 'a');
        }
        for(int i = 0;i < n;i++) {
            ans = min(ans, c + suf[i]);
            c += (s[i] == 'b');
        }
        return ans;
    }
};
