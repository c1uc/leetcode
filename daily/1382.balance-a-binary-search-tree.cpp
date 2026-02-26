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
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        auto dfs = [&](this auto&& dfs, TreeNode* x) -> void {
            if(x->left) dfs(x->left);
            nodes.emplace_back(x->val);
            if(x->right) dfs(x->right);
        };
        dfs(root);
        auto build = [&](this auto&& build, int l, int r) -> TreeNode* {
            if(l == r) return nullptr;
            int m = (l + r) / 2;
            auto ln = build(l, m);
            auto rn = build(m + 1, r);
            return new TreeNode(nodes[m], ln, rn);
        };
        return build(0, nodes.size());
    }
};
