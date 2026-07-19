class Solution {
public:
    int findGCD(vector<int>& nums) {
        int s = 1001, m = 0;
        for(auto x: nums) {
            s = min(s, x);
            m = max(m, x);
        }
        return gcd(s, m);
    }
};
