#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for (int i = 0; i < answers.size(); i++) {
            mp[answers[i]]++;
        }
        int ans = 0;
        for (auto [key, value] : mp) {
            ans += (value + key) / (key + 1) * (key + 1);
        }
        return ans;
    }
};
