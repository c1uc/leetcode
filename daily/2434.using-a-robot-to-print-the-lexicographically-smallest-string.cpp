#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        string robotWithString(string s) {
            int n = s.size();
            vector<int> mn(n);
            mn[n - 1] = s[n - 1];
            for(int i = n - 2; i >= 0; i--) {
                mn[i] = min(mn[i + 1], s[i]);
            }
            string ans;
            stack<char> st;
            for(int i = 0; i < n; i++) {
                st.push(s[i]);
                while(!st.empty() && st.top() <= mn[i]) {
                    ans += st.top();
                    st.pop();
                }
            }
            while(!st.empty()) {
                ans += st.top();
                st.pop();
            }
            return ans;
        }
    };
