class Solution {
public:
    int getCommon(vector<int>& v1, vector<int>& v2) {
        int a = 0, b = 0, m = v1.size(), n = v2.size();
        while(a < m && b < n) {
            if(v1[a] == v2[b]) return v1[a];
            else if(v1[a] < v2[b]) a++;
            else b++;
        }
        return -1;
    }
};
