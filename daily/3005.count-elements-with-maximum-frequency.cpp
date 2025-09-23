class Solution {
    public:
        int maxFrequencyElements(vector<int>& nums) {
            vector<int> v(101, 0);
            for(auto x: nums) v[x]++;
            int ans = 0, mx = -1;
            for(auto f: v) {
                if(f == mx) ans += f;
                else if(f > mx) ans = f, mx = f;
            }
            return ans;
        }
    };