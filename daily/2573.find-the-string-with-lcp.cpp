class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        vector<char> s(n, 0);
        int i = 0;
        for(auto c = 'a';c <= 'z';c++) {
            for(int j = i;j < n;j++) if(lcp[i][j]) s[j] = c;
            while(i < n && s[i]) i++;
            if(i == n) break;
        }
        if(i < n) return "";
        for(int i = n - 1;i >= 0;i--) for(int j = n - 1;j >= 0;j--) {
            int l;
            if(s[i] != s[j]) l = 0;
            else if(i == n - 1 || j == n - 1) l = 1;
            else l = lcp[i + 1][j + 1] + 1;
            if(l != lcp[i][j]) return "";
        }
        return s | ranges::to<string>();
    }
};
