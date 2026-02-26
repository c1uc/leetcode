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
    bool isBalanced(TreeNode* root) {
        auto dfs = [&](this auto&& dfs, TreeNode* x) -> pair<int, bool> {
            if(!x) return {0, false};
            auto [ld, lc] = dfs(x->left);
            auto [rd, rc] = dfs(x->right);
            if(lc || rc || abs(ld - rd) > 1) return {0, true};
            return {max(ld, rd) + 1, false};
        };
        return !dfs(root).second;
    }
};
