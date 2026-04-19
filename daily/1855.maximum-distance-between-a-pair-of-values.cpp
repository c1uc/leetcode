class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), ans = 0;
        for(int i = 0, j = 0;i < n && j < m;) {
            if(nums1[i] > nums2[j]) i++;
            else {
                ans = max(ans, j - i);
                j++;
                if(i > j) j = i;
            }
        }
        return ans;
    }
};
