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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* r, int x) -> int {
            if(r == nullptr) return 0;
            x = (x << 1) + r->val;
            if(r->left == nullptr && r->right == nullptr) sum += x;
            else {
                dfs(r->left, x);
                dfs(r->right, x);
            }
            return sum;
        };
        return dfs(root, 0);
    }
};
