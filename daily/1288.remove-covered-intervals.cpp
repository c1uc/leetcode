class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        ranges::sort(intervals, [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0] || a[0] == b[0] && a[1] > b[1];}, {});
        int s = 0, mx = 0;
        for(auto v: intervals) {
            if(v[1] > mx) {
                mx = v[1];
                s++;
            }
        }
        return s;
    }
};
