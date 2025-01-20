//
// Created by duck on 2024/9/10.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool dfs(ListNode* head, TreeNode* root) {
        if(!head) {
            return true;
        }
        if(!root) {
            return false;
        }
        if(head->val != root->val) {
            return false;
        }
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) {
            return false;
        }
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

signed main() {_

    return 0;
}
