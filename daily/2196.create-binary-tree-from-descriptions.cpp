/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

vector<TreeNode*> vec(1e5 + 1, nullptr);
vector<int> pa(1e5 + 1, 0);

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        ranges::fill(vec, nullptr);
        ranges::fill(pa, 0);
        auto get = [&](int x) {
            if(vec[x] == nullptr) vec[x] = new TreeNode(x);
            return vec[x];
        };
        for(auto& d: descriptions) {
            auto p = get(d[0]), ch = get(d[1]);
            if(d[2]) p->left = ch;
            else p-> right = ch;
            pa[d[1]]++;
        }
        for(int i = 0;i < 1e5 + 1;i++) if(vec[i] != nullptr && pa[i] == 0) return vec[i];
        return nullptr;
    }
};
