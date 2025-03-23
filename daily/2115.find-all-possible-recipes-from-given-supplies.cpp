/*
 * @lc app=leetcode id=2115 lang=cpp
 *
 * [2115] Find All Possible Recipes from Given Supplies
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int idx = 0;
        unordered_map<string, int> mp;
        
        auto add = [&](vector<string> &v) -> void {
            for(auto &s: v) {
                if(mp.count(s)) continue;
                mp[s] = idx++;
            }
        };

        add(recipes);
        add(supplies);
        for(auto &v: ingredients) add(v);

        vector<vector<int>> g(idx);
        vector<int> in_deg(idx, 0);

        for(int i = 0; i < recipes.size(); i++) {
            in_deg[mp[recipes[i]]] = ingredients[i].size();

            for(auto &s: ingredients[i]) {
                g[mp[s]].emplace_back(mp[recipes[i]]);
            }
        }
        
        queue<int> q;
        for(auto &s: supplies) {
            q.emplace(mp[s]);
        }

        vector<string> ans;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto &v: g[u]) {
                in_deg[v]--;
                if(in_deg[v] == 0) {
                    q.emplace(v);
                    ans.emplace_back(recipes[v]);
                }
            }
        }

        return ans;
    }
};
// @lc code=end

