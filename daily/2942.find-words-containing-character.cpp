#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i = 0; i < words.size(); i++) {
            if(words[i].find(x) != string::npos) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
