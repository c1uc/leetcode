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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!k) return head;
        int n = 0;
        ListNode* last;
        for(auto cur = head; cur != nullptr;cur = cur->next) {
            n++;
            last = cur;
        }
        if(!n) return head;
        k %= n;
        k = n - k;
        last->next = head;
        auto cur = head, prev = last;
        for(int i = 0;i < k;i++) prev = cur, cur = cur->next;
        prev->next = nullptr;
        return cur;
    }
};
