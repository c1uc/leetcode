class Solution {
    public:
        int countValidSelections(vector<int>& nums) {
            int sum = accumulate(nums.begin(), nums.end(), 0);
            int ans = 0, c = 0, half = sum >> 1;
            for(auto x: nums) {
                c += x;
                if(!x && c == half) ++ans;
                if(!x && c == (sum - half)) ++ans;
            }
            return ans;
        }
    };