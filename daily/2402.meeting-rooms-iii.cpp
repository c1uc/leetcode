#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;


class Solution {
    public:
        int mostBooked(int n, vector<vector<int>>& meetings) {
            sort(meetings.begin(), meetings.end());
            vector<int> cnt(n);
            priority_queue<int, vector<int>, greater<int>> available;
            priority_queue<pii, vector<pii>, greater<pii>> in_use;
            for (int i = 0; i < n; i++) {
                available.push(i);
            }
            for (auto& meeting : meetings) {
                ll start = meeting[0], end = meeting[1];
                while (!in_use.empty() && in_use.top().first <= start) {
                    auto [_, room] = in_use.top();
                    in_use.pop();
                    available.push(room);
                }
                
                if (available.empty()) {
                    auto [_, room] = in_use.top();
                    end = end - start + in_use.top().first;
                    in_use.pop();
                    available.push(room);
                }

                int room = available.top();
                available.pop();
                in_use.push({end, room});
                cnt[room]++;
            }
            for(auto& c : cnt) {
                cout << c << " ";
            }
            cout << endl;
            return max_element(cnt.begin(), cnt.end()) - cnt.begin();
        }
    };
