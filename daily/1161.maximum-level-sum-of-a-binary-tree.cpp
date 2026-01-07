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
 typedef pair<TreeNode*, int> pii;

 class Solution {
 public:
     int maxLevelSum(TreeNode* root) {
         long long max_sum = -LLONG_MAX, sum = 0;
         int cur_depth = 1, max_depth = -1;
         queue<pii> q;
         q.emplace(root, 1);
         while(!q.empty()) {
             auto [ptr, dep] = q.front();
             q.pop();
 
             if(ptr->left) q.emplace(ptr->left, dep + 1);
             if(ptr->right) q.emplace(ptr->right, dep + 1);
 
             if(dep != cur_depth) {
                 if(sum > max_sum) {
                     max_sum = sum;
                     max_depth = cur_depth;
                 }
                 cur_depth = dep;
                 sum = 0;
             }
             sum += ptr->val;
         }
         if(sum > max_sum) {
             max_depth = cur_depth;
         }
         return max_depth;
     }
 };
