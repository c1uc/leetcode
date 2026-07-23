class Solution {
public:
    string smallestSubsequence(string s) {
        int occ = 0;
        string res;
        vector<int> lst(26, 0);
        auto get = [](char c) { return c - 'a'; };
        for(auto [i, c]: s | views::enumerate) lst[get(c)] = i;
        for(auto [i, c]: s | views::enumerate) {
            if(occ & (1 << get(c))) continue;
            while(!res.empty() && res.back() > c && lst[get(res.back())] > i) {
                occ ^= (1 << get(res.back()));
                res.pop_back();
            }
            res += c;
            occ |= 1 << get(c);
        }
        return res;
    }
};
