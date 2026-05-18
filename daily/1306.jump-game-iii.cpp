class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        return [&](this auto&& dfs, int x) -> bool {
            if(arr[x] < 0) return false;
            if(arr[x] == 0) return true;
            int dis = arr[x];
            arr[x] = -1;
            if(x + dis < arr.size() && dfs(x + dis)) return true;
            if(x - dis >= 0 && dfs(x - dis)) return true;
            return false;
        }(start);
    }
};
