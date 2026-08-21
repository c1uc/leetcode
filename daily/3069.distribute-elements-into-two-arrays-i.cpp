class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> v1, v2;
        v1.emplace_back(nums[0]);
        v2.emplace_back(nums[1]);
        for(auto x: nums | views::drop(2)) {
            if(*v1.rbegin() > *v2.rbegin()) v1.emplace_back(x);
            else v2.emplace_back(x);
        }
        return vector<vector<int>>{v1, v2} | views::join | ranges::to<vector<int>>();
    }
};
