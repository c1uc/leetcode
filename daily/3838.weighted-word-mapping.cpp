class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& w) {
        return words | views::transform( [&](string s) { return (25 - ranges::fold_left(s, 0, [&](int acc, char c) { return (acc + w[c - 'a']) % 26; } )) + 'a'; } ) | ranges::to<string>();
    }
};
