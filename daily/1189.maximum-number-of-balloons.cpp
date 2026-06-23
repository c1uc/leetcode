class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> v(26, 0);
        for(auto c: text) v[c - 'a']++;
        return min({v[0], v[1], v['l' - 'a'] / 2, v['o' - 'a'] / 2, v['n' - 'a']});
    }
};
