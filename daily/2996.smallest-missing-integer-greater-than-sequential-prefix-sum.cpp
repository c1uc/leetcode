class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st;
        int s = nums[0], n = nums.size();
        bool flag = true;
        for(int i = 0;i < n;i++) {
            if(flag && i) {
                if(nums[i] == nums[i - 1] + 1) s += nums[i];
                else flag = false;
            }
            st.insert(nums[i]);
        }
        while(st.count(s)) s++;
        return s;
    }
};
