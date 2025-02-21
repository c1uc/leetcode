/*
 * @lc app=leetcode id=1261 lang=cpp
 *
 * [1261] Find Elements in a Contaminated Binary Tree
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

class FindElements {
public:
    unordered_set<int> s;
    FindElements(auto&& root) {
        auto f = [&](auto&& r, int v, auto&& self) -> void {
            if(!r) return;
            r->val = v;
            s.insert(v);
            self(r->left, 2 * v + 1, self);
            self(r->right, 2 * v + 2, self);
        };
        f(root, 0, f);
    }
    
    bool find(int target) {
        return s.find(target) != s.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end

