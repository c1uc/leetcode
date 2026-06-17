class Solution {
public:
    string processStr(string s) {
        return ranges::fold_left(s, "", [](string s, char c) { return c == '#' ? s + s : (c == '%' ? string(s.rbegin(), s.rend()) : (c == '*' ? (s.empty() ? s : s.substr(0, s.size() - 1)) : s + c)); } );
    }
};
