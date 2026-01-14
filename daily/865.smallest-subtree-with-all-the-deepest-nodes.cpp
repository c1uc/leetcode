#include <bits/stdc++.h>
using namespace std;

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
        TreeNode* subtreeWithAllDeepest(TreeNode* root) {
            int max_d = -1, max_c = 0;
            auto dfs1 = [&](this auto&& dfs1, TreeNode* u, int d) -> void {
                if(!u) {
                    if(d > max_d) {
                        max_d = d;
                        max_c = 1;
                    } else if(d == max_d) {
                        max_c += 1;
                    }
                    return;
                }
                dfs1(u->left, d + 1);
                dfs1(u->right, d + 1);
            };
            TreeNode* ans = nullptr;
            dfs1(root, 0);
            auto dfs2 = [&](this auto&& dfs2, TreeNode* u, int d) -> int {
                if(!u) return (d == max_d);
                int c = dfs2(u->left, d + 1) + dfs2(u->right, d + 1);
                if(c == max_c && !ans) ans = u;
                return c;
            };
            dfs2(root, 0);
            return ans;
        }
    };