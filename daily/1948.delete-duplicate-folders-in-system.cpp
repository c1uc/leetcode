#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct Node {
    string name;
    map<string, Node*> children;
    bool is_deleted = false;
    Node(string name): name(name), is_deleted(false) {}
};


class Solution {
    public:
        vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
            Node* root = new Node("");
            for(auto& path: paths) {
                Node* cur = root;
                for(auto& folder: path) {
                    if(cur->children.find(folder) == cur->children.end()) {
                        cur->children[folder] = new Node(folder);
                    }
                    cur = cur->children[folder];
                }
            }

            unordered_map<string, Node*> cnt;
            auto node_to_str = [&](this auto&& self, Node* node) -> string {
                if(node->children.empty()) {
                    return node->name;
                }
                string subtree = "";
                for(auto& [name, child]: node->children) {
                    subtree += "(" + self(child) + ")";
                }
                if(cnt.find(subtree) == cnt.end()) {
                    cnt[subtree] = node;
                } else {
                    cnt[subtree]->is_deleted = true;
                    node->is_deleted = true;
                }
                return node->name + "(" + subtree + ")";
            };

            vector<vector<string>> ans;
            vector<string> path;
            
            auto dfs = [&](this auto&& self, Node* node) -> void {
                if(node->is_deleted) {
                    return;
                }
                if(node != root) {
                    path.push_back(node->name);
                    ans.push_back(path);
                }
                for(auto& [name, child]: node->children) {
                    self(child);
                }
                if(node != root) {
                    path.pop_back();
                }
            };
            
            node_to_str(root);
            dfs(root);
            return ans;
        }
    };
