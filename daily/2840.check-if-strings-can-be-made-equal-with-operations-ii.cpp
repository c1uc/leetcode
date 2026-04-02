int cnt[2][26];

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0;i < s1.size();i++) {
            cnt[i & 1][s1[i] - 'a']++;
            cnt[i & 1][s2[i] - 'a']--;
        }
        for(int i = 0;i < 26;i++) if(cnt[0][i] || cnt[1][i]) return false;
        return true;
    }
};
