#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        auto cmp = [](const string& a, const string& b) {
            int diff = 0;
            for(int i = 0; i < a.length(); i++) {
                if(a[i] != b[i]) {
                    diff++;
                }
            }
            return diff;
        };

        vector<int> dp(n, 1);
        vector<int> pre(n, -1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(groups[i] != groups[j] && words[i].length() == words[j].length() && cmp(words[i], words[j]) == 1) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }
        }
        int max_len = 0;
        int max_idx = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] > max_len) {
                max_len = dp[i];
                max_idx = i;
            }
        }
        vector<string> ans;
        while(max_idx != -1) {
            ans.emplace_back(words[max_idx]);
            max_idx = pre[max_idx];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};