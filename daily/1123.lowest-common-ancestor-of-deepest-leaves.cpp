/*
 * @lc app=leetcode id=1123 lang=cpp
 *
 * [1123] Lowest Common Ancestor of Deepest Leaves
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxd = -1;
        TreeNode* ans = nullptr;

        auto f = [&](this auto&& f, TreeNode* u, int d) -> int {
            maxd = max(maxd, d);
            if(u == nullptr) {
                return d;
            }

            int l = f(u->left, d + 1);
            int r = f(u->right, d + 1);

            if(l == maxd && r == maxd) {
                ans = u;
            }
            
            return max(l, r);
        };

        f(root, 0);

        return ans;
    }
};
// @lc code=end

