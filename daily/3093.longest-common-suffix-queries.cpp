class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<array<int, 26>> ch;
        vector<int> rep;
        
        ch.push_back({});
        rep.push_back(-1);
        
        for(const auto& [i, s] : wordsContainer | views::enumerate) {
            int cur = 0;
            
            auto replace = [&](int node) {
                if(rep[node] == -1 || s.length() < wordsContainer[rep[node]].length()) {
                    rep[node] = i;
                }
            };
            
            replace(cur);
            
            for(const auto& c : s | views::reverse) {
                int idx = c - 'a';
                if(ch[cur][idx] == 0) {
                    ch[cur][idx] = ch.size(); 
                    ch.push_back({});
                    rep.push_back(-1);
                }
                cur = ch[cur][idx];
                replace(cur);
            }
        }
        
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        
        for(const auto& q : wordsQuery) {
            int cur = 0;
            for(const auto& c : q | views::reverse) {
                int idx = c - 'a';
                if(ch[cur][idx] == 0) break;
                cur = ch[cur][idx];
            }
            ans.push_back(rep[cur]);
        }
        
        return ans;
    }
};
