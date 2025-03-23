struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
 */

// @lc code=start
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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        vector<TreeNode*> stk;
        stk.push_back(new TreeNode(preorder[0]));

        for (int i = 1, j = 0; i < preorder.size(); ++i) {
            TreeNode* node = new TreeNode(preorder[i]);
            while (stk.back()->val == postorder[j]) {
                stk.pop_back();
                ++j;
            }
            if (!stk.back()->left) {
                stk.back()->left = node;
            } else {
                stk.back()->right = node;
            }
            stk.push_back(node);
        }

        return stk[0];
    }
};
// @lc code=end

