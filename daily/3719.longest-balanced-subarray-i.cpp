class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int l = 0;l < n;l++) {
            array<int, 100001> arr = {0};
            int c[2] = {0};
            for(int r = l;r < n;r++) {
                int x = nums[r];
                if(!arr[x]) c[x & 1]++;
                arr[x]++;
                if(c[0] == c[1]) ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};
