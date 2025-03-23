struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * @lc app=leetcode id=1028 lang=cpp
 *
 * [1028] Recover a Tree From Preorder Traversal
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
    TreeNode* recoverFromPreorder(string traversal) {
        int idx = 0, val, depth;
        auto get_next_pair = [&]() -> void {
            int d = 0;
            while (idx < traversal.size() && traversal[idx] == '-') {
                ++d;
                ++idx;
            }
            int v = 0;
            while (idx < traversal.size() && traversal[idx] != '-') {
                v = v * 10 + (traversal[idx] - '0');
                ++idx;
            }
        
            depth = d;
            val = v;
        };

        get_next_pair();

        auto recover = [&](int cur_depth, auto&& f) -> TreeNode* {
            if (depth != cur_depth) {
                return nullptr;
            }
            auto root = new TreeNode(val);
            get_next_pair();
            root->left = f(cur_depth + 1, f);
            root->right = f(cur_depth + 1, f);
            return root;
        };

        return recover(0, recover);
    }
};
// @lc code=end

