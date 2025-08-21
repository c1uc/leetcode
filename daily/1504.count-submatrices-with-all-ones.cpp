#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> tii;


class Solution {
    public:
        int numSubmat(vector<vector<int>>& mat) {
            int n = mat.size(), m = mat[0].size(), ans = 0;
            vector<int> height(m, 0);
            for(auto row : mat) {
                for(int i = 0; i < m; i++) {
                    height[i] = row[i] == 0 ? 0 : height[i] + 1;
                }
                stack<tii> st;
                int pre, c, _;
                st.emplace(-1, 0, -1); // idx, pre total square, pre height
                for(int i = 0; i < m; i++) {
                    while(get<2>(st.top()) >= height[i]) {
                        st.pop();
                    }
                    tie(pre, c, _) = st.top();
                    c += height[i] * (i - get<0>(st.top()));
                    ans += c;
                    st.emplace(i, c, height[i]);
                }
            }
            return ans;
        }
    };
