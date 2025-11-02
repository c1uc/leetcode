class Solution {
    public:
        int minNumberOperations(vector<int>& target) {
            int n = target.size(), ans = 0;
            for(int i = 0;i < n;i++) {
                int df = target[i] - (i > 0 ? target[i - 1] : 0);
                if(df > 0) ans += df;
            }
            return ans;
        }
    };