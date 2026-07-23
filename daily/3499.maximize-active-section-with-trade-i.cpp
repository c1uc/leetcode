class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> l;
        int flag = 0, cnt = 0, tot = 0, mx = 0;
        for(auto c: s) {
            tot += (c == '1');
            if(c == '0' + flag) cnt++;
            else {
                flag = !flag;
                l.emplace_back(cnt);
                cnt = 1;
            }
        }
        l.emplace_back(cnt);
        for(int i = 1;i + 1 < l.size();i += 2) if(l[i - 1] && l[i + 1]) mx = max(mx, l[i - 1] + l[i + 1]);
        return tot + mx;
    }
};
