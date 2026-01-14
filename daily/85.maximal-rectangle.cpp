#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            auto solve = [&](vector<int> h) -> int {
                h.push_back(-1);
                int n = h.size(), ans = 0;
                stack<int> st;
                st.push(-1);
                for(int i = 0;i < n;i++) {
                    int ht = h[i];
                    while(st.size() > 1 && h[st.top()] >= ht) {
                        int hh = st.top();
                        st.pop();
                        int l = st.top();
                        ans = max(ans, (i - l - 1) * h[hh]);
                    }
                    st.push(i);
                }
                return ans;
            };
            int mx = 0;
            vector<int> heights(matrix[0].size(), 0);
            for(int row = 0;row < matrix.size();row++) {
                for(int c = 0;c < matrix[0].size();c++) {
                    if(matrix[row][c] == '1') heights[c]++;
                    else heights[c] = 0;
                }
                mx = max(mx, solve(heights));
            }
            return mx;
        }
    };
