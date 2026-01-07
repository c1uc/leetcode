#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

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
        int maxProduct(TreeNode* root) {
            auto dfs = [&](this auto&& dfs, TreeNode* u) -> int {
                if(!u) return 0;
                int left = dfs(u->left);
                int right = dfs(u->right);
                u->val += left + right;
                return u->val;
            };
            int total = dfs(root);
            long long ans = 0;
            auto dfs2 = [&](this auto&& dfs2, TreeNode* u) -> void {
                if(!u) return;
                dfs2(u->left);
                dfs2(u->right);
                ans = max(ans, 1ll * (total - u->val) * u->val);
            };
            dfs2(root);
            return ans % MOD;
        }
    };
