#include <bits/stdc++.h>
#include <ranges>
using namespace std;


class Solution {
    public:
        vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
            vector<int> ans(numberOfUsers, 0), online(numberOfUsers, 0);
            sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
                return stoi(a[1]) < stoi(b[1]) || (stoi(a[1]) == stoi(b[1]) && a[0] > b[0]);
            });
            for(const auto& event : events) {
                string type = event[0], timestamp = event[1], user = event[2];
                int t = stoi(timestamp);
                if(type == "MESSAGE") {
                    if(user == "ALL") {
                        for(auto& it : ans) it++;
                    } else if(user == "HERE") {
                        for(int i = 0; i < numberOfUsers; i++) {
                            if(online[i] <= t) ans[i]++;
                        }
                    } else {
                        vector<int> ids = views::split(user, ' ') | views::transform([](auto&& subarr) {
                            return stoi(subarr | views::drop(2) | ranges::to<string>());
                        }) | ranges::to<vector<int>>();
                        for(auto& id : ids) {
                            ans[id]++;
                        }
                    }
                } else {
                    online[stoi(user)] = t + 60;
                }
            }
            return ans;
        }
    };
