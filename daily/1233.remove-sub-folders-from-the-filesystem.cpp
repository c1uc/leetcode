#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        vector<string> removeSubfolders(vector<string>& folder) {
            sort(folder.begin(), folder.end());
            vector<string> ans;
            unordered_set<string> st;
            for(string& f : folder) {
                int n = f.size();
                for(int i = 1; i < n; i++) {
                    if(f[i] == '/' && st.count(f.substr(0, i))) {
                        break;
                    }
                    if(i == n - 1) {
                        ans.push_back(f);
                        st.insert(f);
                    }
                }
            }
            return ans;
        }
    };

