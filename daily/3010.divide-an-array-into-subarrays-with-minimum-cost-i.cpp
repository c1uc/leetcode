class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int mn[2] = {nums[1], nums[2]};
        if(mn[0] > mn[1]) {
            int tmp = mn[0];
            mn[0] = mn[1];
            mn[1] = tmp;
        }
        for(auto x: nums | views::drop(3)) {
            if(x <= mn[0]) {
                mn[1] = mn[0];
                mn[0] = x;
            } else if(x <= mn[1]) {
                mn[1] = x;
            }
        }
        return nums[0] + mn[0] + mn[1];
    }
};
