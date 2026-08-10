class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector suf(n + 1, 0);
        int t = m - 1;
        suf[n] = m;
        for(int i = n - 1;i >= 0;i--) {
            if(t > 0 && word1[i] == word2[t]) --t;
            suf[i] = t + 1;
        }
        bool c = false;
        t = 0;
        vector<int> res;
        for(int i = 0;i < n;i++) {
            if(word1[i] == word2[t]) {
                res.emplace_back(i);
                t++;
            } else if(!c && suf[i + 1] <= t + 1) {
                res.emplace_back(i);
                c = true;
                t++;
            }
            if(res.size() == m) return res;
        }
        return {};
    }
};
