using namespace std;

bool mm[10001];

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        memset(mm, false, sizeof(mm));
        int s = 0, ans = 0, l = 0;
        for(int r = 0; r < nums.size();r++) {
            if(mm[nums[r]]) {
                while(nums[l] != nums[r]) {
                    s -= nums[l];
                    mm[nums[l++]] = false;
                }
                l++;
            } else {
                s += nums[r];
                mm[nums[r]] = true;
                ans = max(ans, s);
            }
        }
        ans = max(s, ans);
        return ans;
    }
};