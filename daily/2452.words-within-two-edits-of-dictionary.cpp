class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for(auto& q: queries) {
            for(auto& t: dictionary) {
                int d = 0;
                for(int i = 0;i < t.size() && d <= 2;i++) {
                    d += (q[i] != t[i]);
                }
                if(d <= 2) {
                    res.emplace_back(q);
                    break;
                }
            }
        }
        return res;
    }
};
