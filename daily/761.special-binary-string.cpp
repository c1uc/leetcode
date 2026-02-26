class Solution {
public:
    string makeLargestSpecial(string s) {
        if(s.size() <= 2) return s;
        vector<string> sub;
        int diff = 0, start = 0;
        for(int i = 0;i < s.size();i++) {
            if(s[i] == '1') diff++;
            else {
                diff--;
                if(diff == 0) {
                    sub.push_back("1" + makeLargestSpecial(s.substr(start + 1, i - start - 1)) + "0");
                    start = i + 1;
                }
            }
        }
        ranges::sort(sub, greater<>());
        return sub | views::join | ranges::to<string>();
    }
};
