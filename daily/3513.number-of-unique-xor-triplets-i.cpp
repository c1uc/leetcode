class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 4;
        // return next power of 2
        return 1 << (32 - __builtin_clz(n));
    }
};
