class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26, 0);
        for(auto& c: word) cnt[c - 'a']++;
        ranges::sort(cnt, greater<>());
        int ans = 0;
        for(int i = 0;i < 26;i++) {
            ans += cnt[i] * (i / 8 + 1);
        }
        return ans;
    }
};
