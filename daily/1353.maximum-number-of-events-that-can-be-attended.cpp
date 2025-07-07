#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        ranges::sort(events, [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0, t = 1;
        while(i < events.size() || !pq.empty()) {
            while(i < events.size() && events[i][0] == t) {
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top() < t) {
                pq.pop();
            }
            if(!pq.empty()) {
                pq.pop();
                ans++;
            }
            t++;
        }
        return ans;
    }
};
