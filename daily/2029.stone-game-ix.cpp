class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c[3] = {0};
        bool flag = true;
        for(const auto& x: stones) c[x % 3]++;
        if(c[1]) {
            if(!(c[2] == c[1] - 1 || c[2] == c[1] - 2) && ~(c[0] + 2 * min(c[1] - 1, c[2]) + (c[1] - 1 > c[2])) & 1) return true;
        }
        if(c[2]) {
            if(!(c[1] == c[2] - 1 || c[1] == c[2] - 2) && ~(c[0] + 2 * min(c[2] - 1, c[1]) + (c[2] - 1 > c[1])) & 1) return true;
        }
        return false;
    }
};
