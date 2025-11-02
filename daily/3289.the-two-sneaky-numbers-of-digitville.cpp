class Solution {
    public:
        vector<int> getSneakyNumbers(vector<int>& nums) {
            unordered_set<int> s;
            vector<int> ans;
            for(auto x: nums) {
                if(s.count(x)) ans.emplace_back(x);
                else s.insert(x);
            }
            return ans;
        }
    };