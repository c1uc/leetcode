const int MAXN = 100;
static int v[MAXN];

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        fill_n(v, n, 1);
        ++v[n - 1];
        for(const auto& x: nums) if(x >= n || --v[x] < 0) return false;
        return true;
    }
};
