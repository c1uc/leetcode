class Solution {
public:
    string decodeCiphertext(string enc, int rows) {
        int n = enc.size(), cols = enc.size() / rows;
        string res = "";
        for(int i = 0;i < n;i++) {
            int d = i / rows, r = i % rows;
            if(d + r >= cols) break;
            int c = d + r;
            res += enc[cols * r + d + r];
        }
        res.erase(res.find_last_not_of(' ') + 1);
        return res;
    }
};
