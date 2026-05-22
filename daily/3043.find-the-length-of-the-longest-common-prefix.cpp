class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        for(auto& x: arr1) {
            while(x) {
                s.emplace(x);
                x /= 10;
            }
        }
        int ans = 0;
        for(auto& x: arr2) {
            while(x) {
                if(s.count(x)) {
                    ans = max(ans, (int)to_string(x).length());
                    break;
                }
                x /= 10;
            }
        }
        return ans;
    }
};
