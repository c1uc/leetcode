/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class Solution {
    public:
        ListNode* modifiedList(vector<int>& nums, ListNode* head) {
            unordered_set<int> num(nums.begin(), nums.end());
            while(head && num.count(head->val)) head = head->next;
            auto cur = head;
            while(cur->next) {
                if(num.count(cur->next->val)) cur->next = cur->next->next;
                else cur = cur->next;
            }
            return head;
        }
    };